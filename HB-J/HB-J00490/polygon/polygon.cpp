#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N];
int n;
int cnt=0;
void dfs(int k,int sum,int maxn)
{
	if(sum>2*maxn)
	{
		cnt++;
		return;
	}
	for(int i=k+1;i<=n;i++)
	{
		dfs(i,sum+a[i],max(maxn,a[i]));
	}
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
	for(int i=1;i<=n;i++)
	{
		dfs(i,a[i],a[i]);
	}
	//ai ya wo zhen shi fu le CCF wo ***** chu zhe me ex de ti mu
	cout<<cnt;
	return 0;
}
