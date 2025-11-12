#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int s0=0,s1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)s0++;
		if(a[i]==1)s1++;
	}
	if(s1>0 && s0==0 && s0+s1==n && k==0){
		cout<<n/2;
	}
	else if(s0>0 && s0+s1==n && k==0){
		int ans=0,s=1;
		for(int i=2;i<=n;i++){
			if(a[i]==1&&a[i-1]==1){
				s++;
			}
			if(a[i]==0||i==n){
				ans+=s/2;
				s=1;
			}
		}
		cout<<ans+s0;
	}
	else if(s0>0 && s0+s1==n && k==1){
		cout<<s1;
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
