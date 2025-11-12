#include<bits/stdc++.h>
typedef long long LL;
#define bit(n) (1<<(n))

LL rd(){
	LL c=getchar(),r=0;bool f=false;
	while(c<'0'||c>'9')f=f||c=='-',c=getchar();
	while(c>='0'&&c<='9'){
		r=r*10+c-'0';
		c=getchar();
	}
	return f?-r:r;
}

namespace solve{
	const LL MAXN=1e4+100,MAXM=1e6+10,MAXK=12;
	LL N,M,K,C[MAXK];
	int ALLC;
	struct _EDGE{
		int u,v;
		LL w;
		int can;
		bool operator<(const _EDGE& b)const{
			return w<b.w;
		}
	};
	std::vector<_EDGE> E;
	void init(){
		N=rd(),M=rd(),K=rd();
		ALLC=(bit(K)<<1)-1;
		for(int i=1;i<=M;i++){
			LL u=rd(),v=rd(),w=rd();
			E.push_back({u,v,w,(ALLC<<1)|1});
		}
		for(int i=1;i<=K;i++){
			C[i]=rd();
			for(int j=1;j<=N;j++){
				LL w=rd();
				E.push_back({N+i,j,w,bit(i)});
			}
		}
		std::sort(E.begin(),E.end());
	}
	int FA[MAXN];
	int fat(int p){
		return (FA[p]==p)?(p):(FA[p]=fat(FA[p]));
	}
	void un(int a,int b){
		FA[fat(a)]=fat(b);
	}
	LL check(int can){
		for(int i=1;i<=N+K+10;i++)FA[i]=i;
		LL ret=0;
		for(int i=1;i<=K;i++)ret+=(can&bit(i))?C[i]:0;
		for(auto& i:E){
			if((i.can&can)&&fat(i.u)!=fat(i.v)){
				ret+=i.w;
				un(i.u,i.v);
			}
		}
		return ret;
	}
	int order[1<<MAXK];
	void outans(LL a){
		FILE* f=fopen("road.out","w");
		fprintf(f,"%lld",a);
		fclose(f);
	}
	void solve(){
		LL ans=1LL<<62;
		
		order[0]=ALLC+1;for(int i=1;i<=ALLC;i++)order[i]=i;
		std::mt19937 gen(time(0));std::shuffle(order,order+ALLC+1,gen);
		
		int uuu=0,obj=std::min(ALLC+1,101);
		while(1){
			for(int uuu=0;uuu<obj;uuu++){
				if(uuu>ALLC)break;
				ans=std::min(ans,check(order[uuu]));
			}
			outans(ans);
			if(double(clock())/CLOCKS_PER_SEC>=0.95)exit(0);
				if(uuu>ALLC)break;
			obj+=20;
			if(uuu==ALLC)break;
		}
	}
}

int main(){
		freopen("road.in","r",stdin);
	#ifndef LOCAL_TEST_
//		freopen("road.out","w",stdout);
	#endif
	solve::init();
	solve::solve();
}
