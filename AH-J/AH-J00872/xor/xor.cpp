#include<bits/stdc++.h>
using namespace std;
int n,ans;
short k;
int a[500005];	
int main() {
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i = 1;i<=n;i++) cin>>a[i];
	int i = 1;
	while (i<=n) {
		int x = 0;
		bool flat = 0;
		for (int j = i;j<=n;j++) {
			x^=a[j];
			if (x==k) {
				flat = 1;
				i = j+1,ans++;
				break;
			}
		}
		if (!flat) i++;
	}
	cout<<ans<<endl;
}
