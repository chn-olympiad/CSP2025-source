#include<bits/stdc++.h>

using namespace std;
int a[500005];
bool dfs(int l,int r,int k){
	int sum=a[l];
	l++;
	for(;l<=r;l++){
		sum=sum^a[l];
	}
	if(sum==k){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	cin>>n>>k;
	
	int he[500005];
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			flag=1;
		}
		// if(i==1){
		// 	he[1]=a[i];
		// 	continue;
		// }
		// he[i]=he[i-1]^a[i];
	}
	// for(int i=2;i<=n;i++){
	// 	for(int j=i+1;j<=n;j++){

	// 	}
	// }

	if(k==0){
		int ans=0;
		if(flag){
			bool vis[10006]={0};
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;

				}else{
					if(a[i]==a[i+1]&&vis[i]!=1){
						ans++;
						vis[i]=1;
						vis[i+1]=1;
					}
				}
			}
			cout<<ans;
		}else{
			cout<<n/2;
		}
		
		return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dfs(i,j,k)){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
