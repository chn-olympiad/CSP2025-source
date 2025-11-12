#include<bits/stdc++.h>
using namespace std;
int n,k;
long long b[500005],ans;
long long top,top1;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		int u;
		cin>>u;
		b[i]=(b[i-1]^u);
		for(int j=top1; j<i; j++) {
			if((b[i]^b[j])==k&&j+1>top1) {
				top1=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
