#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans=0;
int a[N],vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(vis,0,sizeof(vis));
	for(int lenn=1;lenn<=n;lenn++){
		for(int i=1;(i+lenn-1)<=n;i++){
			int l=i;
			int r=i+lenn-1;
			if(vis[l]==1||vis[r]==1){
				break;
			}
			int cnt=a[l];
			for(int j=l+1;j<=r;j++){
				if(vis[j]==1){
					break;
				}
				cnt^=a[j];
			}
			if(cnt==k){
				ans++;
				for(int j=l;j<=r;j++){
					vis[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
