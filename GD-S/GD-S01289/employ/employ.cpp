#include<bits/stdc++.h>
#define ll long long
#define int ll
#define oF(l,r,i) for(int i=l;i<=r;i++)
#define of(l,r) for(int i=l;i<=r;i++)
#define tF(n,i) oF(1,n,i)
#define tf(n) oF(1,n,i)
#define nF(i) oF(1,n,i)
#define nf() oF(1,n,i)
#define pb emplace_back
#define pint pair<int,int>
#define mp make_pair
#define f first
#define s second
#define file(x) (freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),0)
#define check(x) file(x);ifstream Ans(#x".ans");
#define mod 998244353
using namespace std;
ll read(){
	ll x=0;
	char c=getchar();
	while(c<48)c=getchar();
	while(c>47)x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return x;
}
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
char gtch(){
	char c=getchar();
	while(c<33)c=getchar();
	return c;
}
string gts(){
	string s="";
	char c=gtch();
	while(c>32)s+=c,c=getchar();
	return s;
}
ll fp(ll a,ll b,ll p=mod){
	int ans=1;
	while(b){
		if(b&1)(ans*=a)%=p;
		(a*=a)%=p;
		b>>=1;
	}
	return ans;
}
int xxx=file(employ);
int n=read(),m=read();
string s='`'+gts();
int c[505];
int f[1<<18|5][19],ppc[1<<18|5];
signed main(){
	nf()c[i]=read();
	sort(c+1,c+n+1);
	if(n<=18){
		f[0][0]=1;
		int U=(1<<n)-1;
		for(int S=1;S<=U;S++){
			ppc[S]=ppc[S&S-1]+1;
			for(int i=1;i<=n;i++){
				if(S>>i-1&1){
					int T=S^(1<<i-1);
					for(int j=0;j<=ppc[T];j++){
						(f[S][j+(s[ppc[S]]=='0'||c[i]<=j)]+=f[T][j])%=mod;
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)ans+=f[U][i];
		write(ans%mod);putchar(10);
		return 0;
	}
	if(n==m){
		nf()if(s[i]=='0'||c[i]==0)return puts("0"),0;
		int ans=1;
		nf()(ans*=i)%=mod;
		write(ans);
	}
	if(m==1){
		int pos=1,ans=1,cnt=0;
		nf()(ans*=i)%=mod;
		int fail=ans;
		nf(){
			while(c[pos]<i&&pos<=n)pos++;
			if(s[i]=='1')(fail*=fp(n-cnt,mod-2)*(pos-cnt-1)%mod)%=mod,cnt++;
		}
		write((ans+mod-fail)%mod);
	}
}
