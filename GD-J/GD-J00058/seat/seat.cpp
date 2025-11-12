#include<bits/stdc++.h>
using namespace std;
int n,m,x[1005],a[105][105],b,bj=1;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>x[i];
		if(i==1)b=x[i];
	}
	sort(x+1,x+1+n*m,cmp);
	int i=1,j=1,z=1;
	while(1)
	{
		a[i][j]=x[z++];
		if(i==n&&bj==1)
		{
			j++;
			bj=0;
		}
		else if(i==1&&bj==0)
		{
			j++;
			bj=1;
		}
		else if(bj==1)i++;
		else i--;
		if(i>n||j>m)break;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==b)
			{
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
