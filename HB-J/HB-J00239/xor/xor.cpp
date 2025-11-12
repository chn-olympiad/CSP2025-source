#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],vis[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if((a[i]==a[i-1] && vis[i]==0 && vis[i-1]==0) || a[i]==0){
				vis[i]=1;
				vis[i-1]=1;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}
	return 0;
}
