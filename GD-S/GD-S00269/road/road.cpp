#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define int long long
const int N=1e4+100,M=2e6+10;
int n,m,k,p[N];
struct node{
	int a,b,c;
} e[M],g[M];
int c[100],a[12][N];
vector<int> d[110];
bool st[M];
int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
bool cmp(node x,node y){
	return x.c<y.c;
}
int kru(int n,int m){
	rep(i,1,n) p[i]=i;
	int ans=0;
	rep(i,1,m){
		int x=find(e[i].a),y=find(e[i].b);
		if(x!=y) p[x]=y,ans+=e[i].c,st[i]=1;
	}
	return ans;
}
int kru2(int n,int m){
	rep(i,1,n) p[i]=i;
	int ans=0;
	rep(i,1,m){
		if(!st[i]) continue;
		int x=find(e[i].a),y=find(e[i].b);
		if(x!=y) p[x]=y,ans+=e[i].c,st[i]=1;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,m) cin>>e[i].a>>e[i].b>>e[i].c;
	sort(e+1,e+m+1,cmp);
	int ans=kru(n,m);
	int mm=0;
	rep(i,1,m) if(st[i]) g[++mm]=e[i];
	m=0;
	rep(i,1,mm) e[++m]=g[i];
	int tt=n;
	rep(i,1,k){
		++n;
		cin>>c[i];
		rep(j,1,tt) cin>>a[i][j],e[++m]={n,j,a[i][j]};
	}
	sort(e+1,e+m+1,cmp);
	rep(i,1,m) st[i]=0;
	rep(i,1,m){
		if(e[i].a>tt) d[e[i].a-tt].push_back(i);
		else st[i]=1;
	}
//	return 0;
	rep(i,0,(1<<k)-1){
		int res=0;
		rep(j,1,k){
			if(i>>(j-1)&1){
				res+=c[j];
				for(int v:d[j]) st[v]=1;
			}
		}
		ans=min(ans,res+kru2(n,m));
		rep(j,1,k){
			if(i>>(j-1)&1){
				for(int v:d[j]) st[v]=0;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/
