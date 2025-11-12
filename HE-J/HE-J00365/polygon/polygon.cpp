#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6000;
int n,sum,f[N],mod=998244353;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>f[i];
	}
	sort(f+1,f+1+n);
	for(int i=1; i<=n-2; i++) {
		if(f[i]+f[i+1]>f[i+2]) sum++;
	}
    out<<sum;
	return 0;
}

