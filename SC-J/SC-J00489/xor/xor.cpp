#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,k;
ll a[100010];
ll ans=0;
ll cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cnt^=a[i];
		if(cnt==k){
			ans++;
			cnt=0;
		}
	}
	cout<<ans;
	
	
	return 0;
}