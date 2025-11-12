#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+20,M=1e4+20,H=13;
int n,m,k,cnt,a,b,c,cnt1,nt;
int h[M],to[N*5],nxt[N*5];
ll ans_tree,p[H],dp[M],w[N*5],dp1[M][H];
bool book[M],f[H];
struct rp{
	int a;
	ll b;
}nk; 
bool operator<(rp a,rp b){
	return a.b>b.b;
}
priority_queue<rp> q; 
void built(int x,int y,ll z){
	nxt[++cnt]=h[x],h[x]=cnt,to[cnt]=y,w[cnt]=z;
	return;
}
void prim(){
	q.push({1,0});ans_tree=0;
	for(int i=2;i<=nt;i++) dp[i]=1e12+5,ans_tree+=dp[i];
	while(!q.empty()){
		bool g=0;
		nk=q.top();q.pop();
		if(book[nk.a]) continue;
		book[nk.a]=1;
		if(nk.a<=n) cnt1++;
		else{
			for(int i=h[nk.a];i;i=nxt[i])
				w[i]-=p[nk.a-n],w[i+1]-=p[nk.a-n];
			f[nk.a-n]=1;
		} 
		for(int i=h[nk.a];i;i=nxt[i])
			if(dp[to[i]]>w[i] && !book[to[i]]){
				ans_tree-=dp[to[i]],ans_tree+=w[i],dp[to[i]]=w[i],q.push({to[i],w[i]}),g=1;
			}
		if(g==0 && nk.a>n){
			f[nk.a-n]=0;
			for(int i=h[nk.a];i;i=nxt[i])
				w[i]+=p[nk.a-n],w[i+1]+=p[nk.a-n];
		}
		if(cnt1==n) break;
	} 
	for(int i=1;i<=k;i++)
		if(!f[i]) ans_tree-=dp[i+n];
	return;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin >> n >> m >> k;
	nt=n+k;
	for(int i=1;i<=m;i++){
		cin >> a >> b >> c;
		built(a,b,c),built(b,a,c);
	} 
	for(int i=1;i<=k;i++){
		cin >> p[i]; 
		for(int j=1;j<=n;j++){
			cin >> b,built(i+n,j,b+p[i]),built(j,i+n,b+p[i]);
		} 
	}
	prim();
	cout << ans_tree;
	return 0; 
} 
