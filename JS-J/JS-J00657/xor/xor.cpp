#include<bits/stdc++.h>
using namespace std;
long long sum[500005],n,k,a[500005];
int ans;
int mp[1050000];
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	memset(mp,-1,sizeof mp);
	for (int i=0;i<=n;i++){
		if (mp[sum[i]^k]==ans){
			ans++;
		}
		mp[sum[i]]=ans;
	}
	cout<<ans;
	return 0;
}
