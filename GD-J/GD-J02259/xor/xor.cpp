#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500050];
int ans;
int flag=1;
int flag1=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
		if(a[i]>1)flag1=0;
	}if(flag){
		if(k==0){
			ans=n/2;
			cout<<ans; 
		}if(k==1){
			ans=n;
			cout<<ans;
		}
	}else if(flag1){
		if(k==1){
			int lin=a[1];
			int sum=0;
			if(a[1]==1)sum++;
			for(int i=2;i<=n;i++){
				if(a[i]==1)sum++;
				if(lin==k){
					ans++;
					lin=a[i];
				}else{
					lin=lin^a[i];
				}
			}cout<<max(ans,sum);
		}else if(k==0){
			int lin=a[1];
			int sum=0;
			if(a[1]==0)sum++;
			for(int i=2;i<=n;i++){
				if(a[i]==0)sum++;
				if(lin==k){
					ans++;
					lin=a[i];
				}else{
					lin=lin^a[i];
				}
			}cout<<max(ans,sum);
		}else{
			cout<<n;
		}
	}
	return 0;
}
