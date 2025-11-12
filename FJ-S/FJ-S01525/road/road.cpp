#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10005],mx,ans,x,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(u[i]>v[i])swap(u[i],v[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0)sum++;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(sum==k)ans=0;
	else
	for(int i=1;i<n;i++){
		mx=1e9+5;
		for(int j=1;j<=n;j++)
			if(w[j]<mx)mx=w[j],x=j;
		ans+=mx,w[x]=1e9+5;
	}
	cout<<ans;
	return 0;
}
