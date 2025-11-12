#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int f=1;
	int n=0;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) {
		n=(n<<3)+(n<<1)+(c^48);
		c=getchar();
	}
	return n*f;
}
const int N=10005;
int n,a[N];
int32_t main() {
	
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	
	n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	sort(a+1,a+n+1);
	if(n<=2) {
		puts("0");
		return 0;
	}
	if(n==3) {
		if(a[1]+a[2]<=a[3])	puts("0");
		else puts("1");
		return 0;
	}
	int maxn=-INT_MAX;
	int sum=0;
	int ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			sum+=a[j];
			maxn=max(maxn,a[j]);
			if(sum>maxn*2) ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

