#include<bits/stdc++.h>
using namespace std;
long long a[5005];
bool vis[5005];
long long n,ans=0;
void dfs(long long step,long long sum,long long mx,long long z){
	if(step>=3){
		if(sum>mx*2){
			ans++;
		}
	}
	for(long long i=0;i<n;i++){
		if(vis[i]==0&&i>=z){
			vis[i]=1;
			dfs(step+1,sum+a[i],max(a[i],mx),i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}

