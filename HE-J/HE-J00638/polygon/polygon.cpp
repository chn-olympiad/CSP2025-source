#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,MOD=998244353;
int n,ans;
int a[N],sum[N];
bool flag,b[N];
bool check() {
	int maxn=0,summ=0;
	for(int i=1; i<=n; i++) {
		if(b[i]) {
			summ+=a[i];
			maxn=max(maxn,a[i]);
		}
	}
	return summ>maxn*2;
}
void dfs(int t) {
	if(t>n) {
		if(check())ans++;
		return;
	}
	b[t]=1;
	dfs(t+1);
	b[t]=0;
	dfs(t+1);
}
int f(int i,int j,int tmp) {
	int l=j,r=i;
	while(l<r) {
		int mid=(l+r)>>1;
		if(sum[mid]-sum[j-1]>tmp) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	return l;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		if(a[i]!=1)flag=1;
	}
	if(n<=20) {
		dfs(1);
		printf("%lld",ans%MOD);
		return 0;
	}
	if(!flag) {
		int anss=1;
		for(int i=1; i<=n; i++)anss=anss*2%MOD;
		int res=(n*n+n)/2+1;
		anss=(anss-res+MOD)%MOD;
		printf("%lld",anss);
		return 0;
	}
	int c[N][N],sumc[N][N];
	memset(c,0,sizeof(c));
	memset(sumc,0,sizeof(sumc));
	for(int i=1; i<=n; i++)c[i][0]=1,c[i][1]=i;
	for(int i=2; i<=n; i++) {
		for(int j=2; j<=i; j++) {
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
		}
	}
	for(int j=1; j<=n; j++) {
		for(int i=j; i<=n; i++) {
			sumc[i][j]=(sumc[i-1][j]+c[i][j])%MOD;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=3; i<=n; i++) {
		int tmp=a[i];//二分结果 > tmp
		for(int j=1; j<i; j++) {
			int w=f(i,j,tmp);
			if(w>=i)continue;
			int len1=i-j-1;
			int len2=w-j;
			int val=(sumc[len1][len2]-sumc[len2-1][len2]+MOD)%MOD;
			ans=(ans+val)%MOD;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
5
1 2 3 4 5

9

5
2 2 3 8 10

6

6
1 1 1 1 1 1

*/
