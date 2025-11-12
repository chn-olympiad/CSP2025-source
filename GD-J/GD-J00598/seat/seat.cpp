#include<iostream>
#include<algorithm>
using namespace std;
int a[100],b[12][12]={};
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
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	int xr=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0,x=1,y=1,t=0;i<n*m;i++)
	{
		b[x][y]=a[t++];
		int x2=x+(y&1)*2-1;
		if(1>x2||x2>n)
			y++;
		else
			x=x2;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==xr)
				cout<<i<<" "<<j<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	return 0;
}
