#include <bits/stdc++.h>
using namespace std;
int m,a[5005];
long long ans=0;
void dfs(int x,int y,int b,int maxn)
{
	if(x>=3&&b>maxn*2){
		ans++;
		ans=ans%998244353;
	}
	for(int i=y+1;i<=m;i++){
		dfs(x+1,i,b+a[i],max(maxn,a[i]));
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
