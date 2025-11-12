#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[200040];
int sum[200040];
int cnt=0;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	sum[0]=0;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int r;
	for (int i=1;i<=n;i++) {
		if (sum[i]==k) {
			r=i;
			cnt++;
			break;
		}
	}
	for (int i=2;i<=n;i++) {
		for (int j=i;j<=(r>=i?r:n);j++) {
			if ((sum[j]^sum[i-1])==k) {
				if (r<i) cnt++;
				r=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}


