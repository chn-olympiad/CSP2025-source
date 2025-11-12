#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],n,s;
void dfs(int cur,int ma,int x,int pos)
{
	if(pos>=3)
	{
		if(ma*2<cur)
		{
			//cout<<cur<<" "<<ma<<" "<<x<<" "<<pos<<endl;
			s++;
		}
		else if(pos==n)
		{
			return ;
		}
	}
	for(int i=x+1;i<=n;i++)
	{
		dfs(cur+a[i],max(ma,a[i]),i,pos+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<500)
	{
		for(int i=1;i<=n-2;i++)
		{
			dfs(a[i],a[i],i,1);
		}
	}
	else
	{
		s=0;
	}
	cout<<s;
	return 0;
}
