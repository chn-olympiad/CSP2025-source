#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;

inline int read(){
	int x=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

inline void write(int x){
	if(x<0){
		putchar('-');
		write(-x); 
		return;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

int n, t, ans;
bool f=1;
const int mod=998244353;

signed main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	n=read();
	vector<int> a(n+1), p(n+1), pre(n+1), dp(n+1);
	vector<vector<int> > c(n+1, vector<int>(n+1));
	for(int i=1;i<=n;++i) a[i]=read(), f=f&&(a[i]==1);
	sort(a.begin(),a.end());
	pre[0]=0;
	for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
	p[0]=1;
	for(int i=1;i<=n;++i) p[i]=p[i-1]*i%mod;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			c[i][j]=p[j]/(p[i]*p[j-i]%mod)%mod;
		}
	}
	if(f){
		for(int i=3;i<=n;++i) (ans+=c[i][n])%=mod;
		write(ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int k=2;k<n;++k){
		for(int r=n;r>k;--r){
			for(int l=1;l<r;++l){
				if(pre[l+k-1]-pre[l-1]<=a[r]) continue;
				dp[k]+=c[k][r-l];
			}
		}
	}
	for(int i=2;i<n;++i) (ans+=dp[i])%=mod;
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}