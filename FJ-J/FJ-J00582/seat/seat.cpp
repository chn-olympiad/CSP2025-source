#include<bits/stdc++.h>
using namespace std;
int a[10020];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,cj=0,cjid=0;
	cin >> n >> m >> a[0];
	cj=a[0];
	int h=n*m;
	for(int i=1;i<h;i++)
	{
		cin >> a[i];
	}
	sort(a,a+h+1,cmp);
	for(int i=0;i<h;i++)
	{
		if(a[i]==cj)
		{
			cjid=i+1;
			break;
		}
	}
	int s=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				s++;
				if(s==cjid)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				s++;
				if(s==cjid)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
