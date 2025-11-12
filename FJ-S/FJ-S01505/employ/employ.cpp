#include<bits/stdc++.h>
using namespace std;
long long a[1000];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=1;
	char c[505];
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int k=1,t=0,x=n;
	for(int i=1;i<=n;i++) {
		if(c[i]=='0') {
			t++;
			if(t>a[k]) {
				k++;
				x--;
			}
		}
		ans=ans*x%998244353;
	}
	printf("%lld",ans);
	return 0;
}