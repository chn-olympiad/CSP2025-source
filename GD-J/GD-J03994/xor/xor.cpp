#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010],vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int las=1,ans=0;
	for(int r=1; r<=n; r++){
		for(int l=las; l<=r; l++){
			int cur=s[r]^s[l-1];
			if(cur==k&&vis[r]==0&&vis[l]==0){
				vis[l]=vis[r]=1;
				ans++;
				las=r+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
