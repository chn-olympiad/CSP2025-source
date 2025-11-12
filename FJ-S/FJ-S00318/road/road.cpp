#include <bits/stdc++.h>//·Ö²ãÍ¼Á¬Í¨¿é 
using namespace std;
#define ll long long
#define pii pair<int,int>
#define endl '\n'
const int N = 1e4+5;
const int M = 2e6+5;
const int K = 12;
struct node{
	int u,v,w;
}edge[M],edg[M];
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){ x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
void write(ll x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,k,cnt,cnt_n;
int fa[N*2];
int c[K],cost[K][N];
vector<pii> G[N];
int ans = 0x3f3f3f3f;
bool sub_A=true;
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	m = read();
	k = read();
	for(int i = 1 ; i <= m ; i ++){
		int u=read(),v=read(),w=read();
//		G[u].push_back(v,w);
//		G[v].push_back(u,w);
		edge[i].u=u;
		edge[i].v=v;
		edge[i].w=w;
	}
	for(int i = 1 ; i <= k ; i ++){
		c[i] = read();
		sub_A=sub_A&&(c[i]==0);
		for(int j = 1 ; j <= n ; j ++){
			cost[i][j]=read();
			sub_A=sub_A&&(cost[i][j]==0);
		}
	}
//	cout << sub_A << endl;
	for(int bits=0 ; bits < (1<<k) ; bits ++){
		if(sub_A) bits = (1<<k)-1;
		int res = 0;
		cnt=m;
		cnt_n=n;
		for(int i = 1;  i<= m ; i ++) edg[i]=edge[i];
		for(int i = 1 ; i <= n+k ; i ++) fa[i]=i;
		for(int i = 1 ; i <= k ; i ++){
			if((1>>(i-1))&bits){
				res += c[i];
				++cnt_n;
				for(int j = 1 ; j <= n ; j ++){
					edg[++cnt].u=n+i;
					edg[cnt].v= j;
					edg[cnt].w = cost[i][j];
				}
			}
			
		}
		sort(edg+1,edg+1+cnt,cmp);
		for(int i = 1 ; i <= cnt ; i ++){
			int awa = edg[i].u,qwq=edg[i].v,cstt=edg[i].w;
			if(find(awa)!=find(qwq)){
				cnt_n--;
				fa[find(awa)]=find(qwq);
				res += cstt;
			}
			if(cnt_n==1) break;
		}
		ans = min(ans,res);
		if(sub_A) break;
	}
	cout << ans << endl;
	return 0;
}

