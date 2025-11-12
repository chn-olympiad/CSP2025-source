#include<iostream>
#include<algorithm>
using namespace std;
int a[105]={0};
int b[15][15]={0};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			t=i;
			break;
		}
	}
	int c=0,r=0;
	while(t)
	{
		c++;
		for(int i=1;i<=n;i++)
		{
			t--;
			r++;
			if(!t)
			{
				cout<<c<<" "<<r;
				return 0;
			}
		}
		c++;
		for(int i=1;i<=n;i++)
		{	
			t--;
			if(!t)
			{
				cout<<c<<" "<<r;
				return 0;
			}
			r--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

