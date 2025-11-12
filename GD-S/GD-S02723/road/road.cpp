#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e4+5,M=2e6+5;
int n,m,k,u,v,cnt,c[15],f[N];
long long ans,sum;
struct edge{int u,v,w;}e[M];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	while(m--){
		cnt++;
		cin>>e[cnt].u>>e[cnt].v>>e[cnt].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];sum+=c[i];
		for(int j=1;j<=n;j++){
			e[++cnt].u=j;e[cnt].v=n+i;
			cin>>e[cnt].w;sum+=e[cnt].w;
		}
	}
	sort(e+1,e+1+cnt,cmp);
	if(sum){
		ans=LLONG_MAX;
		for(int i=0;i<(1<<k);i++){
			sum=0;
			for(int j=1;j<=n+k;j++)f[j]=j;
			for(int j=0;j<k;j++)
				if((i>>j)&1)sum+=c[j+1];
			for(int j=1;j<=cnt;j++){
				if(e[j].v>n&&!((i>>(e[j].v-n-1))&1))
					continue;
				u=find(e[j].u);v=find(e[j].v);
				if(u!=v){f[u]=v;sum+=e[j].w;}
			}
			ans=min(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}
