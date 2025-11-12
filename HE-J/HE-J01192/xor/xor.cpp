#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,ans,now=0;
int a[1000000];
int sum[1000000];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			now=i;
			ans++;
			continue;
		}
		for(int j=now;j<=i;j++){
			if((sum[i]^sum[j])==k){
				ans++;
				now=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
