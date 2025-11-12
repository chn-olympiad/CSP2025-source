#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum = n*m;
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
	}
	int k = a[1];
	sort(a+1,a+sum+1);
	int p;
	int pow =0;
	for(int i=sum;i>=1;i--)
	{
		pow++;
		if(a[i] == k)
		{
			p =pow;
			break;
		}
	}
	cout<<endl;

	int x =1,y=1;
	int num =0;
	for(int i=1;i<p;i++)
	{
		if(y==n&&num==0)
		{
			x++;
			num++;
		}
		else if(y==1&&x!=1)
		{
			if(num==0)
			{
				x++;
				num++;
			}
		}
		else if(x%2!=0)
		{
			y++;
			num =0;
		}
		else
		{
			y--;
			num =0;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}