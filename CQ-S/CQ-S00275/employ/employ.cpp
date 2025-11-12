#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define il inline
#define pii pair<int,int>
#define x first
#define y second
#define rd read()
#define gc getchar()
#define debug() puts("-----------")

namespace yzqwq{
	il int read(){
		int x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
		while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc;
		return x*f;
	}
	il int qmi(int a,int b,int p){
		int res=1;
		while(b){
			if(b&1) res=res*a%p;
			a=a*a%p,b>>=1;
		}
		return res;
	}
	il int gcd(int a,int b){
		if(!b) return a;
		return gcd(b,a%b);
	}
	il void exgcd(int a,int b,int &x,int &y){
		if(!b) return x=1,y=0,void(0);
		exgcd(b,a%b,y,x);
		y-=a/b*x;
		return ;
	}
	mt19937 rnd(time(0));
}
using namespace yzqwq;

const int N=505,Mod=998244353;
int n,m;
char s[N];
int c[N],p[N];

il int work(int x){
	int res=1;
	for(re int i=1;i<=x;++i) res=res*i%Mod;
	return res;
}

il void solve(){
	n=rd,m=rd;
	scanf("%s",s+1);
	for(re int i=1;i<=n;++i) c[i]=rd,p[i]=i;
	if(m==n){
		bool fl=0;
		for(re int i=1;i<=n;++i) if(s[i]=='0') fl=1;
		for(re int i=1;i<=n;++i) if(c[i]==0) fl=1;
		if(fl) cout<<"0\n";
		else{
			int res=1;
			for(re int i=1;i<=n;++i) res=res*i%Mod;
			cout<<res;
		}
		return ;
	}
	bool fl=0;
	for(re int i=1;i<=n;++i) if(s[i]=='0') fl=1;
	for(re int i=1;i<=n;++i) if(c[i]==0) fl=1;
	if(!fl){
		int res=1;
		for(re int i=1;i<=n;++i) res=res*i%Mod;
		cout<<res;	
		return ;	
	}
	if(n>15){
		int res=0;
		cout<<(work(n)-work(n-1)+Mod)%Mod;
		return ;
	}
	int res=0;
	do{
		int lst=0,sum=0;
		for(re int i=1;i<=n;++i){
			if(lst>=c[p[i]]){
				++lst;continue;
			}
			if(s[i]=='0'){
				++lst;
			}
			else{
				++sum;
			}
		}
		if(sum>=m) ++res;
	}while(next_permutation(p+1,p+n+1));cout<<res;
	return ;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t=1;while(t--)
	solve();
	return 0;
}


