#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long sum,cnt;
int vis[5005];
void dfs(int num,int ans,int id,int maxx,int y){
	if(num>=3){
		if(ans>maxx*2){
			cnt++;
		}
	}
	for(int i=id;i<=n;i++){
		if(!vis[i]&&i>y){
			vis[i]=1;
			y=i;
			dfs(num+1,ans+a[i],id+1,max(maxx,a[i]),y);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum*=2;
	dfs(0,0,1,0,0);
	cout<<cnt%998244353;
	return 0;
}
