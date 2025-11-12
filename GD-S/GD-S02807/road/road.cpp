#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+17;
const int M=1e6+7;
ll n,m,k;
ll cj[11];
ll c[11][N];
struct Edge{
	int s1,s2;
	ll v;
} ed[2*M];
int cnt;
int fa[N];
bool cmp(Edge a,Edge b){
	return a.v<b.v;
}
int find(int x){
	if(x==fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
ll kru(){
	sort(ed,ed+cnt,cmp);
	int hs=0;
	ll ans=0;
	for(int i=0;i<cnt;i++){
		if(hs==n-1){
			break;
		}
		int t1=find(ed[i].s1),t2=find(ed[i].s2);
		if(t1!=t2){
			ans+=ed[i].v;
			hs++;
			fa[t1]=fa[t2];
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&ed[cnt].s1,&ed[cnt].s2,&ed[cnt].v);
		cnt++;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&cj[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
		}
	}
	if(k>0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll res=c[1][i]+c[1][j];
				for(int l=2;l<=k;l++){
					res=min(c[l][i]+c[l][j],res);
				}
				ed[cnt].s1=i;
				ed[cnt].s2=j;
				ed[cnt].v=res;
				cnt++;
			}
		}
	}
	cout << kru();
	return 0;
}
