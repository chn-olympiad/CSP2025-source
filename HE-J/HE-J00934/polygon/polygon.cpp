#include<bits/stdc++.h>
using namespace std;
int sum;
const int MAXN=5*1e3+5,MOD=998244353;
int l[MAXN],n;
void dfs(int s,int m,int pre)
{
	if(s==m+1)
	{
		sum++;
		sum%=MOD;
		return;
	}
	for(int i=pre+1;i<=n;i++)
	{
		dfs(s+1,m,i);
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
		cin>>l[i];
	}
	for(int i=4;i<=n;i++)
	{
		dfs(1,i,0);
	}
	cout<<sum;
	fclose(stdin);fclose(stdout);
	return 0;
}
