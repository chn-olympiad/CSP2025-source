#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[5005];
bool v[5005];
void dfs(int sum,int maxa,int c,int p)
{
	if(sum>2*maxa&&c>=3)
	{
		cnt++;
	}
	for(int i=p;i<=n;i++)
	{
		if(v[i]==false)
		{
			v[i]=true;
			dfs(sum+a[i],max(maxa,a[i]),c+1,i+1);
			v[i]=false;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,0,1);
	cout<<cnt;
}
