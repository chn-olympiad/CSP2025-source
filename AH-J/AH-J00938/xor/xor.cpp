#include<bits/stdc++.h>
using namespace std;
int n,a[200005],k,ans;
bool vis[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++){
			if((a[i-1]==1&&a[i]==1&&vis[i-1]==0&&i!=1)||a[i]==0){
				ans++,vis[i]=1;
			}
		}
	}
		
	else {
		for(int i=1;i<=n;i++){
			if((a[i]==1)||(a[i]!=a[i-1]&&vis[i-1]==0&&i!=1)||(a[i]==0&&a[i-1]==0&&i!=1&&vis[i-1]==0))ans++,vis[i]=1;
		}
	}
	cout<<ans;
	return 0;
}
