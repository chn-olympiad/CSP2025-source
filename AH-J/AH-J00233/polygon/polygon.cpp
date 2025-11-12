#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,mp[5010],a[5010],m,ans;
void dfs(int x,int sum,int mx,int t){
	if(x>m){
		if(mx*2<sum)ans++;
		return;
	}
	for(int i=t+1;i<=n;i++){
		a[x]=mp[i];
		dfs(x+1,sum+mp[i],max(mx,mp[i]),i);
	}
}		
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>mp[i];
	for(m=3;m<=n;m++)dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
