#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];	
	} 
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=0;
	for(int i=1;i<=n*m;i++)
	{
		
		if(c%2==1)
		{
			if(r==n)
			{
				c++;
			}
			else 
				r++;
		}
		else
		{
			if(r==1)
			{
				c++;
			}
			else
				r--;
		}
		if(a[i]==s)
		{
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
 } 