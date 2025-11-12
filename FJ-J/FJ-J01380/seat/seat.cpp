#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],seat[12][12],i=1,j=1,flag;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int sum=n*m,r=0;
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+sum+1,cmp);
	int k=1;
	while(1)
	{
		if(flag)
		break;
		if(j%2==1)
		{	
			for(int i=1;i<=n;i++)
			{
				//cout<<j<<" "<<i<<"\n";
				if(a[k]==r)
				{
					cout<<j<<" "<<i;
					flag++;
					break;
				}
				k++;
			}
			j++;
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				//cout<<j<<" "<<i<<"\n";
				if(a[k]==r)
				{
					cout<<j<<" "<<i;
					flag++;
					break;
				}
				k++;
			}
			j++;
		}
	}
	/*for(int i=1;i<=sum;i++)
	{
		cout<<a[i]<<" "<<i<<"\n";
	}*/
	return 0;
}
