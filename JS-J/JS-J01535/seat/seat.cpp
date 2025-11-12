#include<bits/stdc++.h>
using namespace std;

int a[105],ans[15][15];
int k=1;

bool cmp(int a,int b)
{
	return a>b;
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
	const int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int wR;
    for(int i=1;i<=n*m;i++)
    {
		if(a[i]==R)
		{
			wR=i;
			break;
		}
	}
	int k=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				ans[j][i]=k;
				if(wR==k)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				k++;
			}
		}
		else
		{
			for(int j=n;j>=1;j++)
			{
				ans[j][i]=k;
				if(wR==k)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
