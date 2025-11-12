#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[10010];
	bool k1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			k1=0;
		}
	}
	if(k1==1&&k==0){
		cout<<n/2;
		return 0;
	}else{
		if(k1==1&&k==1){
			cout<<n;
			return 0;
		}
	}
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}else{
				if(a[i+1]==1){
					i++;
					ans++;
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
	}
	cout<<ans;
	return 0;
}