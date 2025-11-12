#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int N = 1e5+120;
int n,m,a[12][N];
int c[20];
int k;
ll ans;
struct node{
	int u,v,w;
}no[1000005],e[N],tmp[1200005];
inline bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[N];
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}

inline void check(int num){
	int idx = n-1;
	ll res = 0;
	int nnum = 0;
	for(int i=1;i<=n-1;i++){
		tmp[i] = e[i];
	}
	for(int i=1;i<=n+20;i++) fa[i] = i;
	for(int i=0;i<k;i++){
		int now = ((num>>i)&1);
		if(now){
			nnum++;
			res += c[i+1];
			for(int j=1;j<=n;j++){
				tmp[++idx] = {n+i+1,j,a[i+1][j]};
			}
		}
	}
	sort(tmp+1,tmp+idx+1,cmp);
	int cnt = 0;
	for(int i=1;i<=idx;i++){
		int fx = find(tmp[i].u),fy = find(tmp[i].v);
		if(fx==fy) continue;
		fa[fx] = fy;
		res += tmp[i].w;
		++cnt;
		if(cnt==n+nnum-1) break;
	}
	ans = min(ans,res);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	int q1,q2,q3;
	for(int i=1;i<=n+100;i++){
		fa[i] = i; 
	}
	for(int i=1;i<=m;i++){
		cin>>q1>>q2>>q3;
		no[i] = {q1,q2,q3};
	}
	sort(no+1,no+m+1,cmp);
	int cnt = 0;
	ll res = 0;
	for(int i=1;i<=m;i++){
		int fx = find(no[i].u),fy = find(no[i].v);
		if(fx==fy) continue;
		fa[fx] = fy;
		e[++cnt] = no[i];
		res += no[i].w;
		if(cnt==n-1) break;
	}
	ans = res;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<(1<<k);i++){
		check(i);
	}
	
	cout<<ans;
	
	return 0;
}
