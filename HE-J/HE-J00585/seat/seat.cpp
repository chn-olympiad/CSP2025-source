#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,cnt=1,a[1005],b[100][100];
int tmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n+1,tmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=a[cnt++];
		}
		i++;
		for(int j=n;j>=1;j--){
			b[i][j]=a[cnt++];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==x){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
