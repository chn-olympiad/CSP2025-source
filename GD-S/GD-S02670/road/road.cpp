#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+50,M=1e6+5;
int n,m,k,c[15],cnt,b[15],ans=LONG_LONG_MAX,fa[N];
struct node{
	int u,v,w;
}e[M*2];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
int work(int ct,int z){
	int sum=0,tmp=0;
	for (int i=1;i<=n+k;i++) fa[i]=i;
	for (int i=1;i<=cnt;i++){
		if (e[i].u>n&&b[e[i].u-n]==0) continue ;
		int u=find(e[i].u),v=find(e[i].v);
		if (u==v) continue ;
		sum+=e[i].w;fa[u]=v;tmp++;
		if (sum+z>=ans) break ;
		if (tmp==ct-1) break ;
	}return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}cnt=m;
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++){
			int x;cin>>x;
			e[++cnt].u=n+i;e[cnt].v=j;e[cnt].w=x;
		}
	}sort(e+1,e+1+cnt,cmp);
	for (int j=0;j<(1<<k);j++){
		int tmp=0,ct=0;
		for (int i=1;i<=k;i++){
			b[i]=(j>>(i-1))&1;
			if (b[i]==1) tmp+=c[i],ct++;
		}ans=min(ans,work(n+ct,tmp)+tmp);
	}cout<<ans<<endl;
	return 0;
}
