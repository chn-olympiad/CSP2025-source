#include<bits/stdc++.h>
#define int long long
using namespace std;
struct _queue{
	int a[1000005],head=1,tail;
	int _front(){return a[head];}
	bool _empty(){return tail<head;}
	void _push(int x){a[++tail]=x;}
	void _pop(){head++;}
};
struct _stack{
	int a[1000005],head;
	int _top(){return a[head];}
	bool _empty(){return !head;}
	void _push(int x){a[++head]=x;}
	void _pop(){head--;}
};
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
const int N=21,mod=998244353;
int n,m,dp[1<<N][N],c[N],S,ans;
int b[1<<N];
string s;
int popcount(int x){
	int s=0;
	while(x) s+=x&1,x>>=1;
	return s;
}
int lb(int x){return x&-x;}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	if(n>20){
		cout<<'0';
		return 0;
	}
	S=(1<<n)-1;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=0;i<n;i++) b[1<<i]=i+1;
	dp[0][0]=1;
	for(int i=0;i<S;i++){
		int x=popcount(i);
		int d=(~i)&S;
		for(int j=0;j<=x;j++){
			int t=d;
			while(t){
				int tp=lb(t),p=i|tp;
				t-=tp;
				if(s[x+1]=='0'||x-j>=c[b[tp]]) dp[p][j]=(dp[p][j]+dp[i][j])%mod;
				else dp[p][j+1]=(dp[p][j+1]+dp[i][j])%mod;
			}
		}
	}
	for(int i=m;i<=n;i++) ans=(ans+dp[S][i])%mod;
	cout<<ans;
	return 0;
}

