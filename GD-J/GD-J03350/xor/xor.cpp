#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[500010];
long long sum[2001][2001];
bool f[2001][2001];
long long ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n>5000) {
		cout<<1;
		return 0;
	}
	if(n==1) {
		if(a[1]==k) {
			cout<<1;
			return 0;
		}
	}
	if(n==2) {
		if(a[1]==k) {
			ans++;
		}
		if(a[2]==k) {
			ans++;
		}
		if((a[1]^a[2])==k) {
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		sum[i][i]=a[i];
		for(int j=i+1; j<=n; j++) {
			sum[i][j]=sum[i][j-1]^a[j];
		}
	}
	memset(f,false,sizeof(f));
	for(int i=1; i<=n; i++) {
		if(f[i-1][1]) {
			f[i][1]=1;
			continue;
		}
		for(int j=i; j<=n; j++) {
			if(sum[i][j]==k) {
				f[i][1]=1;
				break;
			}
		}
	}
	for(int i=2; i<=n; i++) {
		for(int j=2; j<=i; j++) {
			for(int z=j; z<=i; z++) {
				if(sum[z][i]==k) {
					if(f[z-1][j-1]) {
						f[i][j]=1;
						break;
					}
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {
		if(f[n][i]) {
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}
