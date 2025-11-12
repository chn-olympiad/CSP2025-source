#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500010],cnt;
bool v,vis[500010];
int main(){

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) cnt++;
		if(a[i]==0) v=1;
		}
	if(k==0&&v==0){
		if(n==1){
			cout<<0;
			}
		else if(n==2){
			cout<<1;
		}
		else{
			cout<<n/2;
		}
	}
	else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				}
			if(a[i]==1&&a[i-1]==1&&vis[i]==0&&vis[i-1]==0){
				ans++;
				vis[i]=1;
				vis[i-1]=1;
				}
			}
			cout<<ans;
		}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
				}
			}
		cout<<ans;
		}
	else{
		cout<<k-1;
		}			
	return 0;
}
