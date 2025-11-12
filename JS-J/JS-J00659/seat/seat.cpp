#include <bits/stdc++.h>
using namespace std;

int a[105]={0};
int b[15][15]={0};

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	int x;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt++;
			cin>>a[cnt];
			//cout<<a[cnt]<<" ";
			if(cnt==1)
			{
				x=a[1];
			}
		}
	}
	//cout<<x<<endl;
	//cout<<endl;
	sort(a+1,a+m*n+1,less<int>());
	/*for(int i=1;i<=m*n;i++)
	{
		cout<<a[i]<<" ";
	}*/
	//cout<<endl;
	cnt=n*m+1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				cnt--;
				b[j][i]=a[cnt];
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				cnt--;
				b[j][i]=a[cnt];
			}
		}
	}
	//cout<<endl;
	//bool flag=true;
	//cout<<endl;
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//cout<<i<<" "<<j;
			if(b[i][j]==x)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
