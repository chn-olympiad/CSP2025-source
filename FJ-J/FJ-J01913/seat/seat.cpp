#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10086];
int b[100][86];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	bool k=false;
	bool kk=false;
	int n,m,z,ans=0,a1;
	cin>>n>>m;
	z=n*m;
	for(int u=1;u<=n*m;u++)
	{
		cin>>a[u];
	}
	a1=a[1];
	int i=0,j=1;
	sort(a+1,a+z+1,cmp);
	while(ans<z)
	{
		ans++;
		if(k==false)
		{
			if(i+1<=n)
			{
				i++;
				b[i][j]=a[ans];
			}
			else if(i+1>n)
			{
				j++;
				b[i][j]=a[ans];
				k=true;
			}
		}
		else if(k==true)
		{
			if(i-1>=1)
			{
				i--;
				b[i][j]=a[ans];
			}
			else if(i-1<1)
			{
				j++;
				b[i][j]=a[ans];
				k=false;
			}
		}
	}
	for(int u=1;u<=n;u++)
	{
		for(int p=1;p<=m;p++)
		{
			if(b[u][p]==a1)
			{
				cout<<p<<' '<<u<<endl;
				kk=true;
				break;
			}
		}
		if(kk==true)
		break;
	}
	return 0;
}
