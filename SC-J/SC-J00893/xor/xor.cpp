#include<bits/stdc++.h>
using namespace std;
int n,k,s[2000010];
int MoonCake2011[2000010],luogu886055[2000010];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]^=s[i-1];
		int pos=luogu886055[s[i]^k];
		if((s[i]^s[pos])==k) MoonCake2011[i]=MoonCake2011[pos]+1;
		MoonCake2011[i]=max(MoonCake2011[i],MoonCake2011[i-1]);
		luogu886055[s[i]]=i;
	}
	cout<<MoonCake2011[n];
	return 0;
}