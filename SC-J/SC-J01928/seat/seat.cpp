#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000006],x;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	bool dr=true;
	int c=1,r=1,p=1;
	while(1)
	{
		if(a[p]==x)
		{
			cout<<c<<" "<<r;
			return 0;
		}
		if(dr)
		{
			if(r==n)
			{				
				c++;
				dr=!dr;	
			} 
			else
			{
				r++;
			}
		}
		else
		{
			if(r==1)
			{
				c++;
				dr=!dr;	
			}
			else
			{
				r--;
			}
		}
		
		p++;
	}
	
	return 0;
} 