#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n;
long long a[5005];
long long sum,maxn,ans;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3) {
		if(sum>maxn*2) {
			cout<<1;
		} else cout<<0;
	} else {
		int w=n;
		long long b=1;
		while(w) {
			b=b*2%M;
			ans=b;
			w--;
		}
		int op=(n*n-n)/2%M;
		long long y=(1+n+op)%M;
		cout<<ans-y;
	}
	return 0;

}

