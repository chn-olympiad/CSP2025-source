#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int s[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);			
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	int a=s[1];
	sort(s+1,s+n*m,cmp);
	int ans=0; 
	for(int i=1;i<=n*m;i++)
	{
		if(s[i]==a)
		{
			ans=i;
		}
	}
	if(ans/n*n==ans)
	{
		if((ans/n)%2==0)
		{
			cout<<ans/n<<" "<<1;
			return 0;
		}
		else
		{
			cout<<ans/n<<" "<<n;
			return 0;
		}
	}
	else
	{
		if((ans/n)%2==0)
		{
			cout<<ans/n+1<<" "<<ans%n;
			return 0;
		}
		else
		{
			cout<<ans/n+1<<" "<<n-ans%n+1;
			return 0;
		}
	}
	return 0;
 } 