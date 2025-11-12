#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,flag=0,flag1=0;
long long a[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]!=a[i-1]&&i!=1)||a[i]!=1) flag=1;
		if(a[i]>1) flag1=1;
	}
	if(flag==0&&k==0){
		cout<<n/2;
	}else if(flag1==0&&k<=1){
		int ans=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]!=a[i+1]&&i!=n){
					ans++;
					i++;
				}else if(a[i]==1){
					ans++;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]&&i!=n){
					ans++;
					i++;
				}else if(a[i]==0){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
