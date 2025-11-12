#include<bits/stdc++.h>
using namespace std;
int f[114514];
int n,m,k,s,mn,ans;
struct p{
	int u;
	int v;
	int w;
}q[114514];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>q[i].u>>q[i].v>>q[i].w;
		f[q[i].u]=q[i].v;
		f[q[i].v]=q[i].u;
	}
	mn=INT_MAX;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>s;
			mn=min(s,mn);
		}
		ans+=mn;
	}
	cout<<mn;
	return 0;
}
