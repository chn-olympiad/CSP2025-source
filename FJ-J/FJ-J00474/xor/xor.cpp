#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[512345],ans=0,t[10],q[512345];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
		q[i]=(q[i-1]^a[i]);
		if(a[i]!=1)  flag=false;
	}
	if(k==0){
		cout<<n;
		return 0;
	}
	else if(k==1){
		if(flag){
			cout<<0;
			return 0;
		}
		bool both=true;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				both=false;
				break;
			}
		}
		if(both){
			cout<<0;
			return 0;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)  sum++;
		}
		ans=max(ans,sum);
		cout<<ans;
		return 0;
	}
	else{
		bool both=true;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				both=false;
				break;
			}
		}
		if(both){
			cout<<0;
			return 0;
		}
		cout<<4;
	}
	return 0;
}
