#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+56;
int n,m,k;
//n,m is the cities and roads in the past
//k is will to build cities
int c[20];//Because k <= 10
struct nod{
	int to;
	int nxt;
	int val;
}aa[maxn];
nod town[maxn];
int h[maxn];
int hb[maxn];
int cnt;
int cnt2;
long long ans;
void add(int a,int b,int c){
	aa[++cnt].to = b;
	aa[cnt].val = c;
	aa[cnt].nxt = h[a];
	h[a] = cnt;
}
void add2(int a,int b,int c){
	town[++cnt2].to = b;
	town[cnt].val = c;
	town[cnt].nxt = hb[a];
	hb[a] = cnt; 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		ans += w;
	}
	for(int i = 1;i <= k; i++){
		scanf("%d",&c[i]);
		ans += c[i];
		for(int j = 1;j <= n; j++){
			int t;
			scanf("%d",&t);
			add(i,j,t);
			add(j,i,t);
			ans += t;
		}
	}
	printf("%lld",ans);
	return 0;
	
}
