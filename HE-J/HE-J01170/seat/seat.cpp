#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freoprn("number.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[n*m];
	for(int i=0;i<n*m;i++)
		cin>>b[i];
	int cheng=b[0];
	sort(b,b+n*m);
	int sum=0;
	for(int i=0;i<n*m;i++)
	{
		sum++;
		if(b[i]==cheng)
			break;
	}
	sum=n*m-sum;
	int x=1,y=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(sum==0)
			{
				cout<<x<<" "<<y;
				return 0;
			}
			if(i%2==0&&j!=m-1)
				y++;
			else if(j==m-1)
				x++;
			else
				y--;
			sum--;
		}
		x++;
	}
	return 0;
}
