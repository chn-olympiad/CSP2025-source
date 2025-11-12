#include<iostream>
#include<algorithm>
using namespace std;
int n,m,c=0,len,cza;
int a[110];
int s[20][20];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i];
		if(i==1)
			cza=a[i];
	}
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i&1)
		{
			for(int j=1;j<=n;j++)
			{
				c++;
				s[i][j]=a[c];
				if(a[c]==cza)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				c++;
				s[i][j]=a[c];
				if(a[c]==cza)
				{
					cout<<i<<' '<<j;
					return 0;
				}	
			}
		}
	}
	return 0;
}
