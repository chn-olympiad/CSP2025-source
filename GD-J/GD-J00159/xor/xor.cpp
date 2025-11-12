#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,k,ans,pos;
ll a[500005],pre[500005];
map<ll,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pre[i]=(pre[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		ll now=pre[i]^pre[pos];
		if(now==k||mp[k^now]>0){
			pos=i;
			ans++;
			mp.clear();
			continue;
		}
		mp[now]++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
