#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,f,n) for(long long i=f;i<=n;i++)
#define dlp(i,a,b) for(long long i=a;i>=b;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')) {
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int mod = 998244353;
int n,a[5005],ans;
void dfs(int k,int num,int sum){
	if(k>=3)if(sum>a[num]*2)ans=(ans+1)%mod;
	ulp(i,num+1,n)dfs(k+1,i,sum+a[i]);
}

signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	int maxn=0;
	ulp(i,1,n){
		a[i]=read();
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(maxn==1){
		write(((n*(n-1)%mod*(n-2)%mod/6+mod))%mod);
		return 0;
	}
	dfs(0,0,0);
	write(ans);
}
