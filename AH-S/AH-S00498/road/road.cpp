#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e4+10,maxm=2e6+10;
int head[maxn],tot,n,m,k,fa[maxn];
struct node{
	int u,v,w;//not star
}a[maxm];
bool cmp(node x,node y){return x.w<y.w;}
int find(int x){if(fa[x]==x) return x;else return fa[x]=find(fa[x]);}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++)
			cin>>a[i].u>>a[i].v>>a[i].w;
		sort(a+1,a+m+1,cmp);
		int sum=0,cnt=0;
		for(int i=1;i<=m;i++)
		{
			int fx=find(a[i].u),fy=find(a[i].v);
			if(fx!=fy) {fa[fx]=fy,cnt++,sum+=a[i].w;}
			if(cnt==n-1) break;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
