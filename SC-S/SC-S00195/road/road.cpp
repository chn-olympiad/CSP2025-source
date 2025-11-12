#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
const int K = 13;
const int M = 1e6+5;
const int N = 1e4+5;

int n,m,k,res,cnt;
int kk[K][N];
int dp[1<<K],fa[N];

struct line{
	int u,v,w;
	bool operator<(const line& y)const{
		return w<y.w;
	}
}a[M];

inline find(const int& x){
	return x==fa[x]?x:find(fa[x]);
}

void kru(){
	for(int x=1;x<=m;x++){
		int xx=find(a[x].u),yy=find(a[x].v);
		if(xx!=yy){
			fa[xx]=yy;
			res+=a[x].w;
			cnt++;
		}
		if(cnt==n-1)
			return;
	}
}

signed main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
	for(int i=1;i<N;i++)
		fa[i]=i;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	std::cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		std::cin>>a[i].u>>a[i].v>>a[i].w;
	}
	
	std::sort(a+1,a+1+m);
	
	kru();
	
	std::cout<<res;
	return 0;
}