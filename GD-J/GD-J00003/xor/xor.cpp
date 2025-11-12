#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],ans;
map<int,int>mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	mp[0]=1;
	for(int i=1;i<=n;i++){
		if(mp[a[i]^k]){
			ans++;
			mp.clear(); 
		}
		mp[a[i]]=1;
	}
	cout<<ans;
	return 0;
}
