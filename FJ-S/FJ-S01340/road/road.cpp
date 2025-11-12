#include<bits/stdc++.h>
using namespace std;
int a[1001],b,n,m,k,u[1001],v[1001],w[1001],p,l[1001],ans;
int main(){
	freopen("road","r",stdin);
	freopen("road","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		l[u[i]]=min(l[u[i]-1],w[i]);
		l[v[i]]=min(l[v[i]-1],w[i]);
	}
	cin>>p;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		l[i]=min(l[i],a[i]);
	}
	for(int i=1;i<=n;i++){
		ans+=l[i];
	}
	cout<<ans<<endl;
	return 0;
}
