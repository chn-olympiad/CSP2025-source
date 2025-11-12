#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],temp,ans;
unordered_map<int,int>mp;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	mp[0]=1;
	cin>>n>>k;for(int i=1;i<=n;i++){
		cin>>a[i];
		temp^=a[i];
		if(mp[temp^k]){
			temp=0;ans++;
			mp.clear();mp[0]=1;
		}
		else mp[temp]=1;
	}
	cout<<ans;
	return 0;
}