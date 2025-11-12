#include <bits/stdc++.h>
using namespace std;
int a[107];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0,c=1,r=1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{	
		cin>>a[i];
		if(a[i]>a[1])
			cnt++;
	}
	if(cnt==0)
		cout<<c<<" "<<r;
	else
	{
		while(cnt--)
		{
			if(c%2)
			{
				if(r==n)
				{	
					c+=1;
					continue;
				}
				r+=1;
			}
			else
			{
				if(r==1)
				{
					c+=1;
					continue;
				}
				r-=1;
			}
		}
		cout<<c<<" "<<r;
	}
	return 0;
}
