#include<bits/stdc++.h>
using namespace std;
namespace cs{
	#define LL long long
	#define fir first
	#define sec second
	typedef pair<int,int> PII;
	const int N=1e4;
	const int M=1e6;
	const int INF=2e9;
	int n,m,k,a,c[15],dsu[N+15],tcnt;
	int Getfa(int x){return dsu[x]==x?x:dsu[x]=Getfa(dsu[x]);}
	LL ans;
	struct Edges{
		int u,v,w,id;
		bool operator <(const Edges& A)const{
			return w<A.w;
		}
	}e[M+5],mst[N+5];
	int pcnt;
	PII p[M+5];
	LL Getmst(int S,int num){
		num+=n-1;
		LL rtn=0;
		for(int i=1;i<=n+k;i++){
			dsu[i]=i;
		}
		int x,y;
		for(int i=1;i<=m;i++){
			if(e[i].id!=0&&(S>>(e[i].id-1)&1)==0) continue;
			x=Getfa(e[i].u);y=Getfa(e[i].v);
			if(x==y) continue;
			dsu[x]=y;
			rtn+=e[i].w;
			num--;
			if(num==0) break;
		}
		return rtn;
	}
	int main(){
		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			dsu[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		sort(e+1,e+m+1);
		int x,y;
		for(int i=1;i<=m;i++){
			x=Getfa(e[i].u);y=Getfa(e[i].v);
			if(x==y) continue;
			dsu[x]=y;
			mst[++tcnt]=e[i];
			ans+=e[i].w;
		}
		m=0;
		for(int i=1;i<=tcnt;i++){
			e[i]=mst[i];
		}
		m=tcnt;
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>a;
				e[++m]={j,i+n,a,i};
			}
		}
		sort(e+1,e+m+1);
		int ppc;
		LL add;
		for(int S=1;S<1<<k;S++){
			ppc=0;add=0;
			for(int i=1;i<=k;i++){
				if((S>>(i-1)&1)^1) continue;
				add+=c[i];
				ppc++;
			}
			ans=min(ans,Getmst(S,ppc)+add);
		}
		cout<<ans<<"\n";
		return 0;
	}
}
int main(){
	cs::main();
	return 0;
}
/*
怎么这道题也有贪心成分……只看 MST 上的边应该是对的吧 
32min 写完 T2 
50min 开始对拍 T2 
51min 对拍出 TLE，共拍数据 15 组 
70min 开始对拍 T2（小数据） 
166min 结束 T2 的对拍，共拍数据 63668 组 
172min 写完 T2 
180min 开始对拍 T2 
234min 结束 T2 的对拍，共拍数据 6558 组 
*/
