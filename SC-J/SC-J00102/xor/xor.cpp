#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500001],p[500001],fl[2000001];
int f[500001],mp[2000001],mx[500001];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=p[i-1]^a[i];
	fl[k]=1;
	for(int i=1;i<=n;i++){
		if(fl[p[i]])f[i]=mx[mp[p[i]]]+1;
		mx[i]=max(mx[i-1],f[i]);
		mp[p[i]^k]=i,fl[p[i]^k]=1;
	}
	cout<<mx[n];
	return 0;
}