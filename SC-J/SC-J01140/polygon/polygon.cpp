#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N];
long long ans;
void dfs(int all,int m,int j)
{
	if(j==n+1)
	{
		if(all>m*2)
			ans++;
		if(ans==998244353)
			ans=0;
		return;
	 } 
	dfs(all+a[j],max(m,a[j]),j+1);
	dfs(all,m,j+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,1);
	cout<<ans;
	return 0;
 } 