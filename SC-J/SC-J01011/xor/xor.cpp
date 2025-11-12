#include<bits/stdc++.h>
#define int long long
using namespace std;
int fdh[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool fa=0,fb=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>fdh[i];
		if(fdh[i]!=1) fa=1;
		if(fdh[i]>1) fb=1;
	}
	if(k==0&&fa==0){
		cout<<n/2;
		return 0;
	}else if(k<=1&&fb==0){
		int ans=0;	
		if(k==1){
			for(int i=1;i<=n;i++) if(fdh[i]==1) ans++;
			cout<<ans;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(fdh[i]==0) ans++;
			else if(fdh[i+1]==1){
				i++;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else{
		int ans=0;
		for(int i=1;i<=n; ){
			if(fdh[i]==k){
				ans++;
				i++;
			}
			int s=fdh[i];
			while(s!=k&&fdh[i]!=k&&i<=n){
				i++;
				s=s^fdh[i];
			}
			if(s==k) ans++;
		}
		cout<<ans;
	}
	return 0;
} 