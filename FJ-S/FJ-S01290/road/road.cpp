#include<bits/stdc++.h>
#define LL long long
#define Un unsigned
#define For1(i,a,b) for(i=(a);i<=(b);++i)
#define For2(i,a,b) for(i=(a);i<(b);++i)
#define FoR1(i,a,b) for(i=(a);i>=(b);--i)
#define FoR2(i,a,b) for(i=(a);i>(b);--i)
#define pii std::pair<int,int>
#define mkp std::make_pair
#define pb emplace_back
#define il inline
#define fir first
#define sec second
#define dbg(x...) (fprintf(stderr,x),fflush(stderr))
#define FI using std::cin;std::ios::sync_with_stdio(0),cin.tie(0)
template<class T1>
il void cmin(T1 &x,T1 y){if(x>y)x=y;}
template<class T1>
il void cmax(T1 &x,T1 y){if(x<y)x=y;}
const int K=10,N=10111,M=1101111;
const LL inf=0x3f3f3f3f3f3f3f3fll;
struct Ed{
	int fro,to,v;
	bool operator<(const Ed&A)const{
		return v<A.v;
	}
};
int fa[1<<K|5][N];
Ed e[M];
int cnt[1<<K|5],c[K+5],n,m,k;
LL ans[1<<K|5],ans2;
int fnd(int id,int x){
	if(x==fa[id][x])return x;
	return fa[id][x]=fnd(id,fa[id][x]);
}
il bool mrg(int id,int x,int y){
	x=fnd(id,x);y=fnd(id,y);
	if(x==y)return 0;
	if(x<y)std::swap(x,y);
	fa[id][x]=y;
	return 1;
}
signed main(){FI;int i,j;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	LL cl=clock();
	cin>>n>>m>>k;
	For1(i,1,m)cin>>e[i].fro>>e[i].to>>e[i].v;
	For1(j,1,k){
		cin>>c[j];
		For2(i,0,(1<<k))if((i>>j-1)&1)ans[i]+=c[j];
		For1(i,1,n){
			cin>>e[++m].v;
			e[m].fro=n+j;e[m].to=i;
		}
	}
	//dbg("%lldms\n",clock()-cl);
	std::sort(e+1,e+m+1);
	For2(i,0,(1<<k)){
		cnt[i]=n+__builtin_popcount(i);
		For1(j,1,n+k)fa[i][j]=j;
	}
	//dbg("%lldms\n",clock()-cl);
	For1(j,1,m){
		For2(i,0,(1<<k)){
			if(e[j].fro>n&&((i>>e[j].fro-n-1)&1)==0)continue;
			auto res=mrg(i,e[j].fro,e[j].to);
			if(res){
				--cnt[i];
				ans[i]+=e[j].v;
			}
			//assert(cnt[i]);
		}
	}
	ans2=inf;
	For2(i,0,(1<<k))cmin(ans2,ans[i]);
	printf("%lld\n",ans2);
	return 0;
}