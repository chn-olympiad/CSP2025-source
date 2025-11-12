#include<bits/stdc++.h>
using namespace std;using ll=long long;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c^'-'?1:-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return x*f;}
const int N=505;const ll mod=998244353;
int n,m;
char s[N];
int c[N];
int Mod(int x){return x>=mod?x-mod:x;}
void add(int&x,int y){x=Mod(x+y);}
namespace sub1{
	int f[19][1<<18],g[19][1<<18];
	void solve(){
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			memcpy(g,f,sizeof f);
			memset(f,0,sizeof f);
			for(int j=0;j<i;j++)for(int S=0;S<(1<<n);S++)if(g[j][S]){
				for(int k=0;k<n;k++)if(!(S>>k&1)){
					int T=(S|(1<<k));
					if(s[i]=='0'||c[k+1]<=j)add(f[j+1][T],g[j][S]);
					else add(f[j][T],g[j][S]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)add(ans,f[i][(1<<n)-1]);
		printf("%d\n",ans);
	}
}
namespace sub2{
	vector<int> pos;
	int sf[1111];
	ll fac[1111];
	void solve(){
		fac[0]=1;
		for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
		for(int i=1;i<=n;i++)if(s[i]=='1')pos.push_back(i);
		int t=pos.size();
		int ans=0;
		for(int S=0;S<(1<<t);S++)if(__builtin_popcount(S)>=m){
			int pw=1,sm=0;
			sf[t]=0;
			for(int i=t-1;~i;i--)if(S>>i&1)sf[i]=sf[i+1]+1;
			else sf[i]=sf[i+1];
			for(int i=0;i<t;i++){
				if(!(S>>i&1)){
					
					sm++;
					continue;
				}
				int x=pos[i]-i-1+sm;
				int ps=upper_bound(c+1,c+1+n,x)-c;
				ps=n-ps+1;
				if(ps>=sf[i+1])pw=(ll)pw*(ps-sf[i+1])%mod;
				else pw=0;
			}
			pw=pw*fac[n-sf[0]]%mod;
//			cerr<<pw<<endl;
//			cerr<<n-sf[0]<<endl;
			ans=(ans+pw)%mod;
		}
		printf("%d",ans);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd(),m=rd();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)c[i]=rd();
	sort(c+1,c+1+n);
	if(n<=18){
		sub1::solve();
		return 0;
	}
	int e=0;
	for(int i=1;i<=n;i++)e+=(s[i]=='1');
	if(e<=18){
		sub2::solve();
		return 0;
	}
	return 0;
}
/*
18 5
110111101101111011
6 0 4 2 1 2 5 4 3 3 4 2 1 2 5 4 3 3

350234
611650
*/

