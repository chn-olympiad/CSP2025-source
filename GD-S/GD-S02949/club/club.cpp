#include<bits/stdc++.h>
typedef long long LL;

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
	const LL MAXN=1e5+10;
	LL N;
	struct _BM{
		LL cha;//v_change
		bool operator<(_BM b)const{
			return cha>b.cha;
		}
	};
	LL max(LL a,LL b,LL c){return std::max(a,std::max(b,c));}
	void init(){
	}
	void solve(){
		std::vector<_BM> BM[4];
		LL ans=0;
		N=rd();
		for(int i=1;i<=N;i++){
			LL a=rd(),b=rd(),c=rd();
			LL g=max(a,b,c);
			if(g==a){
				BM[0].push_back({a-std::max(b,c)});
			}else if(g==b){
				BM[1].push_back({b-std::max(a,c)});
			}else{
				BM[2].push_back({c-std::max(a,b)});
			}
			ans+=g;
		}
		for(int i=0;i<=2;i++){
			std::sort(BM[i].begin(),BM[i].end());
			while(BM[i].size()>(N/2)){
				ans-=BM[i].back().cha;
				BM[i].pop_back();
			}
		}
		printf("%lld\n",ans);
	}
}

int main(){
	#ifndef LOCAL_TEST_
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	#endif
	solve::init();
	int T=rd();
	while(T--){
		solve::solve();
	}
}
