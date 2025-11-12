#include<bits/stdc++.h>
using namespace std;
int a,b,x[1005],k,p[105][105];
bool cmp(int g,int h)
{
	return g>h;
}
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++) cin>>x[i];
	k=x[1];
	sort(x+1,x+a*b+1,cmp);
	for(int i=1;i<=b;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=a;j++)
			{
				if(x[(i-1)*a+j]==k)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=a;j>=1;j--)
			{
				if(x[i*a-j+1]==k)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
