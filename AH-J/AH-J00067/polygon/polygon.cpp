#include<bits/stdc++.h>
using namespace std;
int a[10005],n;
long long ans=0;
void dfs(int x,int s,int m,int idx)
{
	if (x>n+1 || idx>n+1) return;
	if (x>=3 && s>m*2) ans++,ans=ans%998244353;
	for (int i=idx;i<=n;i++)
		dfs(x+1,s+a[i],max(m,a[i]),i+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (n<3)
	{
		cout<<0;
		return 0;
	}
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}
