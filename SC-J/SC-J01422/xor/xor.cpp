#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else if(n==2){
		if(a[1]==k){
			ans++;
		}
		if(a[2]==k){
			ans++;
		}
		if(ans==0){
			if(a[1]^a[2]==k){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}else{
				int y=a[i];
				if(a[i]!=0){
					while(y!=k){
						y^=a[++i];
						if(i>n){
							cout<<ans;
							return 0;
						}
					}
					ans++;
					i++;
				}
				
				
			}
		}
		cout<<ans;
	}
	
	return 0;
} 