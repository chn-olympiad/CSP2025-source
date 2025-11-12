#include <bits/stdc++.h>
using namespace std;
int a[100000];
int b[1000][1000];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	a[0]=r;
	for(int i=1;i<(n*m);i++)
	{
		cin>>a[i];
	}
	sort(a,a+(n*m),cmp);
	int p=1,q=1;
	for(int i=0;i<(n*m);i++)
	{

		if(p>=1&&p<=n)
		{
			b[p][q]=a[i];
			p++;
		}
		else
		{
			p-=n;
			q++;
			b[p][q]=a[i];
			p++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==r)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
