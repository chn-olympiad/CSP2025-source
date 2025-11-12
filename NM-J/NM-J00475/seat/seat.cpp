#include<bits/stdc++.h>
using namespace std;
int a[1001001];
int b[101][101];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
		cin>>a[i];
	int temp=a[1];
	sort(a+1,a+n*m+1,cmp);
	int len=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[++len]==temp)
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
				if(a[++len]==temp)
				{
					cout<<i<<" "<<j;
					break;
				}
		}
	}
	return 0;

}
