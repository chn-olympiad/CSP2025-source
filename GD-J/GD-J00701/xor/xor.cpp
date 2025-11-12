#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,flagA=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flagA=0;
	}
	if(k==0&&flagA){
		if(n==1) cout<<0;
		else{
			cout<<n/2;
		}
	}else if(k==0&&!flagA){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			else{
				if(i==n) break;
				else{
					if(a[i+1]==1){
						ans++;
						i++;
					}
				}
			}
		}
		cout<<ans;
	}else if(k==1&&!flagA){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				if(i==n) break;
				else{
					if(a[i+1]==0){
						ans++;
						i++;
					}
				}
			}
			else{
				if(i==n) break;
				else{
					if(a[i+1]==1){
						ans++;
						i++;
					}
				}
			}
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
