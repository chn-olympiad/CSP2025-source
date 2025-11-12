#include<bits/stdc++.h>
using namespace std;
int n,a[10000],s[10000];
long long ans;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		s[i]=s[i-1]+a[i];
	}
	int i=1;
	for(int j=3; j+i-1<=n; j++) {
		for(; i<=n&&j+i-1<=n; i++) {
			int r=i+j-1;
			if(s[t]-s[i-1]>=2*a[r]) {
				ans++;
				ans%=998244353;
			}
		}
		i=1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
