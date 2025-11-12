#include<bits/stdc++.h>
using namespace std;
int a[10005],n,s=0;
const int MOD=998244353;
bool v[10005];
void dfs(int id,int sum)
{
	for(int i=id;i<=n;i++)
	{
		if(sum>a[i])
		{
			s++;
			s%=MOD;
		}
		dfs(i+1,sum+a[i]);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	s%=MOD;
	cout<<s;
	return 0;
}
