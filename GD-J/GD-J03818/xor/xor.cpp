#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=500005,M=2000005;
int n,k,a[N],f[N],b[M];
signed main(){
#ifndef XYZ
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]^=a[i-1];
	memset(f,0xc0,sizeof(f));
	memset(b,0xc0,sizeof(b));
	b[0]=f[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],b[a[i]^k]+1);
		b[a[i]]=max(b[a[i]],f[i]);
	}
	cout<<f[n];
	return 0;
}

