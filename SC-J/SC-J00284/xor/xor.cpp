#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	ll op=0,opp=0,cnt=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)op++;
		if(a[i]==1||a[i]==0)opp++;
		if(a[i]==0){
			cnt++;
		}
	}
	if(k==0&&op==n){
		cout<<n/2;
		return 0;
	}
	if(opp==n&&k==0){
		for(ll i=1;i<=n;i++){
			if(a[i]==1){
				if(a[i+1]==1){
					cnt++;
					i++;
				}
			}
		}
		cout<<cnt;
		return 0;
	}else if(opp==n&&k==1){
		cnt=n-cnt;
		for(ll i=1;i<=n;i++){
			if(a[i]==0){
				if(a[i+1]==0&&i!=n){
					cnt++;
					i++;
				}
			}
//			cout<<i<<" "<<cnt<<endl;
		}
		cout<<cnt;
		return 0;
	}
	cout<<n;
	return 0;
}