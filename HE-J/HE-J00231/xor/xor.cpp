#include<bits/stdc++.h>
#define int long long
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
const int N=6e5+50;
int n,k,a[N];
int32_t main() {
	
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	
	n=read();
	k=read();
	bool f1=1;
	bool f2=1;
	for(int i=1; i<=n; i++) {
		a[i]=read();
		if(a[i]!=1) f1=0;
	}
	if(f1) {
		if(k!=1) {
			puts("0");
			return 0;
		} else {
			printf("%lld\n",n);
			return 0;
		}
	}
	int sum=1;
	int ans=0;
	for(int i=1; i<=n; i++) {
		sum^=a[i];
		if(sum==k) {
			ans++;
			sum=1;
		}
	}
	if(ans==0)
		for(int i=1;i<=n;i++)
			if(a[i]==k) ans++;
	printf("%lld\n",ans);
	return 0;
}

