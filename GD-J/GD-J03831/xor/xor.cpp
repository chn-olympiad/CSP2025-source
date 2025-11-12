#include<bits/stdc++.h>
using namespace std;
int n,k,a[20005],ans;
bool vis[20005];
long long now;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		now=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				vis[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==1)continue;
			now=a[i];
			if(now==k){
				ans++;
				continue;
			}
			for(int j=i+1;j<=n;j++){
				if(vis[j]==1)break;
				now^=a[j];
				if(now==k){
					ans++;
					i=j;
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
				vis[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==1)continue;
			now=a[i];
			if(now==k){
				ans++;
				continue;
			}
			for(int j=i+1;j<=n;j++){
				if(vis[j]==1)break;
				now^=a[j];
				if(now==k){
					ans++;
					i=j;
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	now=0;
	for(int i=1;i<=n;i++){
		now=a[i];
		if(now==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			now^=a[j];
			if(now==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
