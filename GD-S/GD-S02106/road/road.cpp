#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,inf=0x3f3f3f3f;
int n,m,k,c[N],fa[M],len[N];
long long ans=1e18; 
struct edge{
	int u,v,w;
	bool operator <(const edge &b)const{
		return w<b.w;
	}
}e[M],a[12][N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>n>>m>>k;
	for(int i=1;i<=m;i++)cin >>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m);
	for(int i=0;i<k;i++){
		cin >>c[i];
		for(int j=1,x;j<=n;j++)cin >>x,a[i][j]={i+n+1,j,x};
		sort(a[i]+1,a[i]+1+n);
	}
	int tot=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		fa[fx]=fy,a[k][++tot]=e[i];
	}
	for(int s=0;s<(1<<k);s++){
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=0;i<=k;i++)len[i]=1;
		int cnt=n-1;
		long long res=0;
		for(int i=0;i<k;i++)if((s>>i)&1)cnt++,res+=c[i];
		while(true){
			int mn=inf,id=k;
			for(int i=0;i<=k;i++)if(((s>>i)&1)||i==k){
				if(i!=k&&len[i]==n+1)continue;
				if(i==k&&len[i]==n)continue;
				if(a[i][len[i]].w<mn)mn=a[i][len[i]].w,id=i;
			}
			int fx=find(a[id][len[id]].u),fy=find(a[id][len[id]].v);
			if(fx==fy){
				len[id]++;
				continue;
			}
			res+=a[id][len[id]].w,fa[fx]=fy,cnt--;
			len[id]++;
			if(!cnt)break;
		}
		ans=min(ans,res);
	}
	cout <<ans;
	return 0;
}

