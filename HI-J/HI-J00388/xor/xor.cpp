#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int f[500005][3];
int sum[2197152];
int tot;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		tot^=a[i];
		int s=tot^k;
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		if(sum[s]!=0||s==0) f[i][1]=f[sum[s]+1][0]+1;
		sum[tot]=i;
	}
	cout<<max(f[n][0],f[n][1]);
	return 0;
}

