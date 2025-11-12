#include<bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;
int n,m,a[N],las[5000005],f[N],k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i],a[i]^=a[i-1];
		if(las[a[i]^k]||(a[i]^k)==0) f[i]=f[las[a[i]^k]]+1;
		f[i]=max(f[i],f[i-1]);las[a[i]]=i;
	}
	cout<<f[n];
	return 0;
}
