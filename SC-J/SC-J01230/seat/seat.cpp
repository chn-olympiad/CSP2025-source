#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=0;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				b[j][i]=a[++x];
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[++x];
			} 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==c){
				cout<<j<<" "<<i;
				break; 
			}
		}
	}
	return 0;
}