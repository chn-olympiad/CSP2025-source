#include<iostream>
#include<cstdio>
#include<algorithm>
int a[105];
int n,m;
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int k=0;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				cnt++;
				if(a[cnt]==k)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else 
		{
			for(int i=n;i>=1;i--)
			{
				cnt++;
				if(a[cnt]==k)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
