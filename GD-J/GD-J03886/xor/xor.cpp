#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=5e5+5,mod=998244353,inf=0x3f3f3f3f;
int n,a[MAXN],k,s[MAXN],f[MAXN];
unordered_map<int,int> mp;
void chkmax(int &x,int newans){
	x=max(x,newans);
}
void init(){
	for(int i=1;i<(1<<20);i++)
		mp[i]=-inf;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	init();
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	mp[k]=f[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		chkmax(f[i],mp[s[i]]+1);
		chkmax(mp[s[i]^k],f[i]);
	}
	cout<<f[n];
	return 0;
}

