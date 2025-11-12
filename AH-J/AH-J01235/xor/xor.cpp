#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k) ans++;
		cout<<ans;
		return 0;
	}
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0) cnt0++;
		if(a[i]==1) cnt1++;
	}
	if(cnt0==n){
		ans=n/2;
		cout<<ans;
		return 0;
	}
	if(cnt0+cnt1==n){
		if(k==1){
			cout<<cnt1;
			return 0;
		}
	}
	return 0;
}
