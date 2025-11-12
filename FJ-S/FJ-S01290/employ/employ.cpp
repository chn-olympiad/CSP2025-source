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
const int mod=998244353;
il int add(int x,int y){return (x+=y)<mod?x:x-mod;}
il void addd(int &x,int y){if((x+=y)>=mod)x-=mod;}
il int sub(int x,int y){return (x-=y)<0?x+mod:x;}
il void subb(int &x,int y){if((x-=y)<0)x+=mod;}
il int mul(int x,int y){return 1ll*x*y%mod;}
il void mull(int &x,int y){x=1ll*x*y%mod;}
const int N=511;
char s[N];
int cntc[N];
int n,m;
bool chka(){int i;
	For1(i,1,n)if(s[i]!=1)return 0;
	return 1;
}
namespace Sbtka{

void main(){int i;
}
}
namespace Sbtk1{
const int K=18;
int f[1<<K|5];
void main(){int i;
	For2(i,0,(1<<n)){
		f[]
	}
}
}
signed main(){FI;int i,t1;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	For1(i,1,n)s[i]^=48;
	For1(i,1,n)cin>>t1,++cntc[t1];
	/*if(chka()){
		Sbtka::main();
		return 0;
	}*/
	Sbtk1::main();
	return 0;
}