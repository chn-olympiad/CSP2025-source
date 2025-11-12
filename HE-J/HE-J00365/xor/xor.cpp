#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6000;
int a[N],n,k,sum;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1) sum++;
	}
	if(k==0) cout<<n/2;
	else cout<<sum;
	return 0;
}

