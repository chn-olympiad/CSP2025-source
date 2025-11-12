#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],qz[500010],l,ans;
int read() {
	int ch = getchar();
	int ans = 0;
	while(ch<='9'&&ch>='0') {
		ans = ans*10+(ch-'0');
		ch = getchar();
	}
	return ans;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = read();
	k = read();
	for(long long i = 1; i<=n; i++)a[i] = read();
	for(long long i = 1; i<=n; i++)qz[i] = qz[i-1] xor a[i];
	l = n;
	for(long long i = n; i>=1; i--) {
		long long pp = 0;
		for(long long j = i; j<=l; j++) if((qz[i-1] xor qz[j])==k)pp = 1;
		if(pp==1) {
			l = i-1;
			ans++;
		}
	}
	cout<<ans<<"\n";
}
