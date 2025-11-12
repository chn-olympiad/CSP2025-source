#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,k,a[MAXN],sum[MAXN],ans;
bool flag=1;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]!=1&&a[i]!=0) {
			flag=0;
		}
	}
	if(flag) {
		for(int i=1; i<=n; i++) {
			if(a[i]==1)ans++;
		}
	} else {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				if((sum[i]^sum[j-1])==k) {
					ans++;
					j=i+1;
					i=i+1;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//4 2 2 1 0 3
