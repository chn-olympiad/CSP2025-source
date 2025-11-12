#include<bits/stdc++.h>
using namespace std;
int const N=5e5+7;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}
		else if(a[i]^a[i+1]==k){
			ans++;
			i++;
		}
	}
	cout<<ans%998244353;
	return 0;
}
