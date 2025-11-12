#include<bits/stdc++.h>
using namespace std;
int c[10000001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int lr;
	int sum=a*b;
	for(int i=1;i<=sum;i++)
	{
		cin>>c[i];
	}
	lr=c[1];
	sort(c+1,c+sum+1);
	int x=1,y=1;
	int t=sum;
	for(y=1;y<=b;y++)
	{
		if(y%2==1)
		{
			for(x=1;x<=a;x++)
			{			
				if(c[t]==lr)
				{
					cout<<y<<" "<<x<<endl;
					return 0;
				}
				t--;
			}
		}
		else
		{
			for(x=a;x>=1;x--)
			{			
				if(c[t]==lr)
				{
					cout<<y<<" "<<x<<endl;
					return 0;
				}
				t--;
			}
		}		
	}
	return 0;
} 