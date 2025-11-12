#include <bits/stdc++.h>
using namespace std;

string s;
int a[100005];
int n;

bool cmp(int x,int y)
{
	return x>y;
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
	
	if(n=3)
	{
		int num=0;		
		for(int i=1;i<=n;i++)
		{
			num+=a[i];
		}
		sort(a+1,a+n+1,cmp);
		if(num>a[1]*2)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	return 0;
 } 
