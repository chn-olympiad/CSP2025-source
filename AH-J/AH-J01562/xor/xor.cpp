#include<bits/stdc++.h>
using namespace std;
int a[500005],vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			else if(a[i]==a[i+1]){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
			else if(i!=n&&a[i]!=a[i+1]){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
//	if(n<=100){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
				vis[i]=1;
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				int x=a[j],f=1;
				if(vis[j]) continue;
				for(int m=j+1;m<=j+i-1;m++){
					if(vis[m]){
						f=0;
						break;
					}
					x^=a[m];
				}
				if(x==k&&f){
					ans++;
					for(int m=j;m<=j+i-1;m++) vis[m]=1;
// 					cout<<i<<" "<<j<<"\n";
				}
			}
		}
		cout<<ans;
//		return 0;
//	}
	return 0;
}
