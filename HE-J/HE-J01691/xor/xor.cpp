#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],dp[5000100],f,f2,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			if(a[i]!=0){
				f2=1;
			}
			f=1;
		}
	}
	if(f==0){
		if(k==1){
			cout<<n;
			return 0;
		}else if(k==0){
			cout<<n/2;
			return 0;
		}else{
			cout<<0;
			return 0;
		}	
	}
	if(f2==0){
		if(k!=0&&k!=1){
			cout<<0;
			return 0;
		}else if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					cnt++;
					i++;
				}
				if(a[i]==0){
					cnt++;
				}
			}
			cout<<cnt;
			return 0;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
			cout<<cnt;
			return 0;
		}
	}
	
	
	return 0;
}
