#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k,ans=0,now=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	map<long long,int>mp;
	for(int i=1;i<=n;i++){
		now^=a[i];
		if(now==k || mp[now^k]){
			ans++;
			mp.clear();
			now=0;
			continue;
		}
		mp[now]=1;
	}
	cout<<ans;
	return 0;
}
