#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int ksm(int x,int y){
	int s=1;while(y){
		if(y&1)s=s*x%mod;
		x=x*x%mod;y>>=1;
	}return s;
}int inv(int x){return ksm(x,mod-2);}
int n,m,a[N],c[N];char ch[N];
namespace solve1{
	int f[1<<18][20],cnt[1<<18];
	int bit(int x,int y){return (x>>y)&1;}
	void add(int &x,int y){
		x+=y;if(x>mod)x-=mod;
	}
	void sol(){
		f[0][0]=1;
		for(int i=1;i<(1<<n);i++)cnt[i]=cnt[i>>1]+(i&1);
		for(int s=0;s<(1<<n)-1;s++)for(int i=0;i<=cnt[s];i++){
			if(!f[s][i])continue;
			for(int j=0;j<n;j++)if(!bit(s,j)){
				int x=(!a[cnt[s]+1]||i>=c[j+1]);
				add(f[s|(1<<j)][i+x],f[s][i]);
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)ans=(ans+f[(1<<n)-1][i])%mod;
		printf("%lld\n",ans);
		// cout<<f[(1<<n)-1][n]<<endl;
	}
}
namespace solve2{
	int cs[N];
	void sol(){
		int ans=1;for(int i=1;i<=n;i++)ans=ans*i%mod;
		for(int i=1;i<=n;i++)cs[c[i]]++;
		for(int i=1;i<=n;i++)cs[i]+=cs[i-1];
		int sum=1,ts=0,ts2=0;
		for(int i=1;i<=n;i++){
			if(a[i]){
				sum=sum*(cs[i-1]-ts)%mod;
				// cout<<i<<" "<<cs[i-1]-ts<<endl;
				ts++;
			}
			else{
				ts2++;sum=sum*ts2%mod;
			}
		}
		ans=(ans-sum)%mod;
		printf("%lld\n",ans);
		// cout<<sum<<endl;
	}
}
#undef int
int main(){
#define int long long
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,ch+1);
	int s[2]={0,0};
	for(int i=1;i<=n;i++)a[i]=ch[i]-'0',s[a[i]]++;
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	// solve2::sol();return 0;
	// solve1::sol();return 0;
	if(n<=18){solve1::sol();return 0;}
	if(m==n){
		if(s[0])puts("0");
		else{
			int mi=n,ans=1;
			for(int i=1;i<=n;i++)
				mi=min(mi,c[i]),ans=ans*i%mod;
			if(!mi)puts("0");
			else printf("%lld\n",ans);
		}
		return 0; 
	}
	if(!s[0]){
		// cerr<<"A"<<endl;
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		printf("%lld\n",ans);return 0;
	}
	if(m==1){solve2::sol();return 0;}
	return 0;
}