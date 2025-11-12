#include<bits/stdc++.h>
using namespace std;
long long n,m,s[10000001],res,x=1,y=1,i;
bool c;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n<=0||m<=0)
	{
		cout<<"1 1";
		return 0; 
	}
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	res=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(s[i]==res)
		{
			cout<<x<<" "<<y<<" ";
			return 0;
		}
		if(i%n==0)
		{
			if(c==0)
			{
				c=1;
				x++;
				continue;
			}
			if(c==1)
			{
				c=0;
				x++;
				continue;
			}
		}
		if(c==0)
		{
			y++;
		}
		else if(c==1)
		{
			y--;
		}
	}
	return 0;
} 
