#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a.begin(),a.end());
	long long p=1;
	for(int i=0; i<n; i++) p=p*2%M;
	long long t=(p-1-n-1LL*n*(n-1)/2)%M;
	if(t<0) t+=M;
	long long c=0;
	for(int i=0; i<n; i++) {
		int maxs=a[i];
		vector<long long> s(maxs+1,0);
		s[0]=1;
		for(int j=0; j<=i; j++) {
			for(int k=maxs; k>=a[j]; k--) s[k]=(s[k]+s[k-a[j]])%M;
		}
		long long ss=0;
		for(int j=0; j<=maxs; j++) ss=(ss+s[j])%M;
		int cnts=i+1;
		long long u=(ss-1-cnts)%M;
		if(u==0) u+=M;
		c=(c+u)%M;
	}
	long long ans=(t-c)%M;
	if(ans<0) ans+=M;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}