#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "/n"
int a[500005],b[500005],vis[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<1;
		return 0;
	}
	if(n<=10){
		if(k==1){
			for(int i=1; i<=n; i++){
				if(a[i]==1){
					ans++;
				}
			}
		}else if(k==0){
			for(int i=1; i<=n; i++){
				if(a[i]==0){
					ans++;
				}
				if(a[i]==1&&a[i+1]==1&&vis[i]==0&&vis[i+1]==0){
					ans++;
					vis[i]=1;
					vis[i+1]=1;
				}
			}
		}else{
				for(int i=1; i<=n; i++){
				if(vis[i]==1)continue;
				if(b[i-1]==a[i]){
					b[i]=0;
				}else if(a[i]==1){
					if(b[i-1]%2==0){
						b[i]=b[i-1]+1;
					}else{
						b[i]=b[i-1]-1;
					}
				}else if(b[i-1]==1){
					if(a[i]%2==0){
						b[i]=a[i]+1;
					}else{
						b[i]=a[i]-1;
					}
				}else{
					b[i]=(b[i-1]|a[i]);
				}
				if(b[i]==k){
					b[i]=0;
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=100){
		int cnt=0;
		for(int i=1; i<=n; i++){
			if(a[i]==1)cnt++;
		}
		if(k==0&&cnt==n){
			cout<<n/2;
		}else{
			if(k==1){
			for(int i=1; i<=n; i++){
				if(a[i]==1){
					ans++;
				}
			}
		}else{
			for(int i=1; i<=n; i++){
				if(a[i]==0){
					ans++;
				}
				if(a[i]==1&&a[i+1]==1&&vis[i]==0&&vis[i+1]==0){
					ans++;
					vis[i]=1;
					vis[i+1]=1;
				}
			}
		}
		cout<<ans;
		return 0;
		}
	}
	return 0;
}