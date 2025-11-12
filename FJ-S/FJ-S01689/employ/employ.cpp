#include<bits/stdc++.h>
using namespace std;
long long const N=1e7+9;
long long n,m,a[N],c[N],mod=998244353,t=0,o=0;
char s;
long long A(long long n,long long m) {
	long long ans=1;
	for(long long i=n;i>=n-m+1;i--) {
		ans*=i;
		ans%=mod;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) {
		cin>>s;
		a[i]=s-'0';
		if(a[i]==1) o++;
	}
	for(long long i=1;i<=n;i++) {
		cin>>c[i];
		if(c[i]<=0) t++;
	}
	if(o<m||n-t<m) {
		puts("0");
		return 0;
	}
	cout<<A(n-t,m);
	cout<<endl<<n-t;
	return 0;
}