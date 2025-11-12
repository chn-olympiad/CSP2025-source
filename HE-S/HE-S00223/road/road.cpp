#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e4+5,M=1e6+5;
int n,m,k,tot,f[N],ans;
vector<PII> vt[N];
struct edge{
	int u,v,w;
}e[M*2];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdout);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int j=1;j<=m;j++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++tot]={u,v,w};
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+1+tot,cmp);
	int cnt=0;
	for(int i=1;i<=tot;i++){
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
	//		cout<<u<<"->"<<v<<" "<<e[i].w<<"\n";
			f[fu]=fv;
			cnt++;
			ans+=e[i].w;
			if(cnt==n-1){
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}
/*
7 7 0
1 2 1
1 3 2
2 4 3
2 5 4
3 5 5
3 6 6
3 7 7
*/
