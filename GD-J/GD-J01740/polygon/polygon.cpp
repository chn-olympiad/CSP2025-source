#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int vis[200005];
long long ans=0;
void dfs(int x){
	if(x>n){
		
		int maxn=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				sum+=a[i];
				maxn=max(maxn,a[i]);
			}
		}
		
		if(sum>maxn*2){
			ans=(ans+1)%998244353;
		}
		return;
	}
	vis[x]=0;
	dfs(x+1);
	vis[x]=1;
	dfs(x+1);
}
bool flag=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag){
		for(int i=3;i<=n;i++){
			long long up=1;
			long long down=1;
			for(int j=1;j<=i;j++){
				down*=j;
			}
			for(int j=n;j>=n-i+1;j--){
				up*=j; 
			}
			ans=ans+(up/down)%998244353;
		}
		cout<<ans;
		return 0;
	}
	
	dfs(1);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
