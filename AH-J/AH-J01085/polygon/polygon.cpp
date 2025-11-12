#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt,vis[5005];
void dfs(long long sum,long long ma,long long tmp){
	if(sum>2*ma) cnt++;
	for(int i=tmp+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(sum+a[i],max(ma,a[i]),i);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}
