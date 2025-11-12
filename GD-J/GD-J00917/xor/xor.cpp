#include<bits/stdc++.h>
using namespace std;
long long nn[500003],n,k,vis[500002];
int main(){

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>nn[i];
	int yu=0;
	for(int i=1;i<=n;i++){
		if(!(nn[i]==1||nn[i]==0))yu=1;
	}
	if(yu==0){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n-1;i++){
				if(nn[i]==0&&nn[i+1]==1&&vis[i]==0&&vis[i+1]==0)ans++,vis[i]=1,vis[i+1]=1;
				if(nn[i]==1&&nn[i+1]==0&&vis[i]==0&&vis[i+1]==0)ans++,vis[i]=1,vis[i+1]=1;
			}
			cout<<ans;
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(nn[i]==1)ans++;
				if(i!=n&&nn[i]==0&&nn[i+1]==0&&vis[i]==0&&vis[i+1]==0)ans++,vis[i]=1,vis[i+1]=1;
			}
			cout<<ans;
		}
	}
	return 0;
}
