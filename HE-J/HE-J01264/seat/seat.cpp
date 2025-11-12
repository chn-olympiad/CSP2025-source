#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[19];
bool cmp(int a11,int b11){
	return a11>b11;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int k=1,aoo=0;
	for(int i=1;i<=m*n;i++){
		cin >> b[i];
	} 
	aoo=b[1];
	sort(b+1,b+1+m*n,cmp);
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				a[i][j]=b[k];
				k++;
			}
		}
		else if(i%2==0){
			for(int j=m;j>=1;j--){
				a[i][j]=b[k];
				k++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(a[i][j]==aoo){
				cout<<i<<" "<<j;
			}
		
		}
	}
	return 0;
}
