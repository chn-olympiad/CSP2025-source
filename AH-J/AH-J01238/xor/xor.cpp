#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005];
map<int,bool>mp;
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
		if(mp[f[i]^k]){
			ans++;
			mp.clear();
		}
		mp[f[i]]=1;
	}
	cout<<ans<<"\n";
	return 0;
}
