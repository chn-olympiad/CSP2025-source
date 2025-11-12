// Author: Mr_Az
// Finish Time: 2025-11-01

#include<bits/stdc++.h>
#define rint register int
#define int long long
#define pb push_back
#define eb emplace_back
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	x=x*f;
	return ;
}
namespace Mr_Az{
	int T=1;
	const int N=508,mod=998244353;
	int n,m;
	ll ans;
	string t;
	bool spjA=1;
	int a[N],s[N];
	inline void solve(){
		read(n);read(m);
		cin>>t;t=" "+t;
		for(rint i=1;i<=n;i++) spjA&=t[i]=='1';
		for(rint i=1;i<=n;i++) read(a[i]);
		if(n<=10){
			for(rint i=1;i<=n;i++) s[i]=i;
			do{
				int cnt=0;
				for(rint i=1;i<=n;i++) if(t[i]=='0'||cnt>=a[s[i]]) cnt++;
				if(n-cnt>=m) ans++;
			}while(next_permutation(s+1,s+n+1));
			printf("%lld\n",ans);
			return ;
		}
		if(m==n){
			ans=1;
			for(rint i=1;i<=n;i++){
				if(s[i]=='0'||a[i]==0){puts("0");return ;}
				ans=ans*i%mod;
			}
			printf("%lld\n",ans);
			return ;
		}
		puts("0");
		return ;
	}
	inline void mian(){if(!T) read(T);while(T--) solve();}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int st=clock();
	Mr_Az::mian();
	int ed=clock();
	cerr<<"time use: "<<ed-st<<" ms.\n"<<endl;
	return 0;
}

