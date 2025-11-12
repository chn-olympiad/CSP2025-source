#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,ans,k,sum;
map<int,int>mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		cin>>x;
		sum^=x;
		if(mp[sum^k]){
			mp.clear();
			mp[0]=1;
			sum=0,ans++;
		}
		mp[sum]=1;
	}
	cout<<ans<<endl;
	return 0;
}
