#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100001],s[1001][1001];
int main( ){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	int x=n*m+1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				x--,s[i][j]=a[x];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				x--,s[i][j]=a[x];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==k){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	
	return 0;
} 
