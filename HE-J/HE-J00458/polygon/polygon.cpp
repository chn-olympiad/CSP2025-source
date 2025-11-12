#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
void read(int &a) {
	a=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-') {
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		a=a*10+c-48;
		c=getchar();
	}
	a*=f;
}
void wr(int a) {
	if(a>9) {
		wr(a/10);
	}
	putchar(a%10+48);
}
void write(int a) {
	if(a<0) {
		a=-a;
	}
	wr(a);
	putchar('\n');
}
int n,a[6000],ans;
void dfs(int maxn,int sum,int id,int shu) {
	if(shu>=3&&sum>maxn*2) {
		ans++;
		ans%=mod;
	}
	for(int i=id+1; i<=n; i++) {
		dfs(max(maxn,a[i]),sum+a[i],i,shu+1);
	}
}
int maxx=-INT_MAX;
int ji[6000];
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1; i<=n; i++) {
		read(a[i]);
		maxx=max(a[i],maxx);
	}
	if(maxx==1) {
		ji[1]=1;
		for(int i=2; i<=n; i++) {
			ji[i]=ji[i-1]*i;
			ji[i]%=mod;
		}
		for(int i=3; i<n; i++) {
			ans+=ji[n]/(ji[i]*ji[n-i]);
			ans%=mod;
		}
		write(ans+1%mod);
		return 0;
	}
	dfs(0,0,0,0);
	write(ans);
	return 0;
}
