#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[100000],flag,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==0){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		for(ll i=1;i<=n;i++) if(a[i]==1) ans++;
		cout<<ans;
		return 0;
	}
	if(k==0){
		for(ll i=1;i<=n;i++){
			if(a[i]==0) ans++;
			if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(ll i=1;i<=n;i++) if(a[i]==k) ans++;
	cout<<ans;
	return 0;
}


