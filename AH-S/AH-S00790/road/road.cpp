#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vec vector<int>
#define ll long long
#define pi pair<int,int>
void in(int &x){
	x=0;int f=1;char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=f;
}
int t,n,m,k,x,y,z,o,val[15];ll ans;
int fa[200005];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct node{
	int x,y,z,fl;
}e[2000005],d[2000005];
bool cmp(node q,node w){return q.z<w.z;}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	in(n);in(m);in(k);
	for(int i=1;i<=m;i++){
		in(x);in(y);in(z);
		e[i]={x,y,z};
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=e[i].x,y=e[i].y;
		x=find(x);y=find(y);
		if(x==y)continue;
		fa[y]=x;
		d[++o]=e[i];ans+=e[i].z;
	}
	for(int i=1;i<=k;i++){
		in(val[i]);
		for(int j=1;j<=n;j++){
			o++;in(d[o].z);
			d[o].x=j;d[o].y=i+n;d[o].fl=i;
		}
	}
	sort(d+1,d+1+o,cmp);
	for(int s=1;s<(1<<k);s++){
		ll sum=0;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=k;i++)if((s>>i-1)&1)sum+=val[i];
		for(int i=1;i<=o;i++){
			if(sum>=ans)break;
			int u=d[i].fl;if(u&&((s>>u-1)&1)==0)continue;
			int x=d[i].x,y=d[i].y;
			x=find(x);y=find(y);
		    if(x==y)continue;
		    fa[y]=x;sum+=d[i].z;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}