#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int MAXN=1e6+10+(10*10000);
ll n,m,k,fa[MAXN],w1[MAXN+20],ans,cnt=1;
//vector<pii> e[MAXN];
struct edge{
	ll u,v,w;
}e[MAXN];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x])return x;
	return (fa[x]=find(fa[x]));
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		fa[i]=i;
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		fa[m+cnt]=m+i;
		cin>>w1[m+cnt];
		for(int j=1;j<=n;j++){
			cin>>e[m+cnt].w;
			e[m+cnt].u=m+i,e[m+cnt].v=j;
			cnt++;
		}
	}
	sort(e+1,e+m+cnt+1,cmp);
	for(int i=1;i<=m+cnt;i++){
		if(find(e[i].u)!=find(e[i].v)){
			//cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
		}
	}
	
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
