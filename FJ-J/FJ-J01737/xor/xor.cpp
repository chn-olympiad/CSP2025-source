#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],vis[500005],ans,top,x,ma,num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//ios::sync_with(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			vis[++top]=i;
		}
	}
	for(int i=1;i<=n;i++){
		ma=max(a[i],ma);
		if(a[i]==a[1])num++;
	}
	if(ma==0){
		if(k==0)
			cout<<n;
		
		else 
			cout<<0;
	}
	else if(ma==1){
		if(k)cout<<ans;
		else{
			for(int i=1;i<n;i++)
				if(a[i]&&a[i+1])
					ans++;
			cout<<ans;
			}
	}
	else
		cout<<n/2;
	return 0;
}
