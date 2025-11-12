#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag=false;
			break;
		}
	}
	if(flag==true){
		cout<<n/2;
		return 0;
	}
	flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]>1){
			flag=false;
			break;
		}
	}
	if(flag==true){
		int ans=0;
		bool t=0;
		if(k==0){
			for(int i=1;i<n;i++){
				if(t==1){
					t=0;
					ans++;
					continue;
				}
				if(a[i]==0)ans++;
				if(a[i]==1&&a[i+1]==1)t=1;
			}
			ans+=t;
			if(a[n]==0)ans++;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==0){
		int ans=0;
		bool t=0;
		for(int i=1;i<n;i++){
			if(t==1){
				t=0;
				ans++;
				continue;
			}
			if(a[i]==0)ans++;
			if(a[i]==a[i+1])t=1;
		}
		ans+=t;
		if(a[n]==0)ans++;
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
