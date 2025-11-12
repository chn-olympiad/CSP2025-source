#include<bits/stdc++.h>
using namespace std;	
int n,m,k,ans;
int a[2000000][5]={},b[2000000][2000000]={},c[2000000]={};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long ans=0;
	for(int i=1;i<=m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		c[a[i][1]]++;
		c[a[i][2]]++;
		ans+=a[i][3];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	cout<<ans; 
}
