#include<bits/stdc++.h>
using namespace std;
const int N=3e6+5,M=1e4+20;
struct bian{
	int u,v,w;
}e[N];
int fa[M],a[M];
bool cmp(bian b1,bian b2){
	return b1.w<b2.w;
}
int root(int x){
	if(fa[x]==x)return x;
	return fa[x]=root(fa[x]);
}
void join(int x,int y){
	x=root(x),y=root(y);
	fa[x]=y;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k<=0){
	long long ans=0;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+n+1,cmp);
	int c,a1;
	
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a1;
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int uu=e[i].u,vv=e[i].v,w1=e[i].w;
		if(root(uu)==root(vv))continue;
		join(uu,vv);
		ans+=w1;
	}
	cout<<ans;
	}
	else{
		long long ans=0;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	
	int c,cnt=m;
	
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int t=1;t<=n;t++){
			for(int d=t+1;d<=n;d++){
				e[++cnt].u=t;
				e[cnt].v=d;
				e[cnt].w=c+a[t]+a[d];
			}
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		int uu=e[i].u,vv=e[i].v,w1=e[i].w;
		if(root(uu)==root(vv))continue;
		join(uu,vv);
		ans+=w1;
	}
	cout<<ans;
	}
	return 0;
}
