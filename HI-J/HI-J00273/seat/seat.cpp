#include<bits/stdc++.h>
using namespace std;
int a[15];
int b[15][15];
bool cmp(int x,int y){
	return x>y;
}   
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//nĞĞmÁĞ
	int n=0,m=0; 
	cin>>n>>m;
 	int ren=n*m;
	for(int i=1;i<=ren;i++){
		cin>>a[i];
	}
	int r=a[1];
	//ÅÅ×ùÎ» 
	sort(a+1,a+ren+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[i][j]=a[j];
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=a[j];
			}
		}
	} 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==r){
				cout<<i<<' '<<j; 
				
			}
		}
	}
	return 0;
}


