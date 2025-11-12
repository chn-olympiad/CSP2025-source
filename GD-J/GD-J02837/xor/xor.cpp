#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=5e5+5,M=2e6+5;
int a[N],s[N];
int f[N],mp[M];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) {cin>>a[i];s[i]=s[i-1]^a[i];}
	memset(mp,-1,sizeof(mp));
	mp[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(mp[s[i]^k]!=-1) f[i]=max(f[i],f[mp[s[i]^k]]+1);
		mp[s[i]]=i;
	}
	cout<<f[n]<<'\n';
	return 0;
}
