#include<bits/stdc++.h>
using namespace std;
int n,a[10000],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2){
		if(k==0 && n==1){
			cout<<0;
			return 0; 
		} 
		if(k==1 && n==1){
			if(a[1]==1) cout<<1;
			else cout<<0;
			return 0;
		}
		if(n==2){
			if(a[1]^a[2]==k) cout<<1;
			else cout<<0;
		}
	}
	if(n>2){
		if(k==0){
			int ans=0;
			int i=1;
			while(i<n){
				if(a[i]==1 && a[i+1]==1){
					ans++;
					i+=2;
				}
				if(a[i]==1 && a[i+1]==0){
					if(a[i+2]==1){
						ans++;
						i+=3;
					}
					else i++;
 				}
				if(a[i]==0 && a[i+1]==0){
					ans++;
					i+=2;
				}
				if(a[i]==0 && a[i+1]==1){
					if(a[i+2]==1){
						ans++;
						i+=3; 
					}
					else i++;
				}
			}
			cout<<ans;
		}
		if(k==1){
			int ans=0;
			int i=1;
			while(i<n){
				if(a[i]==1 && a[i+1]==0){
					ans++;
					i+=2;
				}
				if(a[i]==1 && a[i+1]==1){
					if(a[i+3]==1){
						ans++;
						i+=3;
					}
					else i++;
				}
				if(a[i]==0 && a[i+1]==1){
					ans++;
					i+=2;
				} 
				if(a[i]==0 && a[i+1]==0){
					if(a[i+2]==1){
						ans++;
						i+=3;
					}
					else i++;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	return 0;
}
