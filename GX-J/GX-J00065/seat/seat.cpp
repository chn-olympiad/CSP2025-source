#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<cstring>
using namespace std;
int x,y;
int b[101][101];
int p[101];
int heng,zong;
int mine,aaa;
int main()
{
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		cin>>x>>y;
		int t;
		t=x*y;
		int a[t];
		for(int i=0;i<=t;i++)
		{
			int x;
			cin>>x;
			a[i]=x;
		}
		mine=a[0];
		sort(a+t,a);
		aaa=0;
		for(int i=1;i<=y;i++)
			for(int j=1;j<=x;j++)
				{	
					if(a[aaa]!=0)	
						{
							b[i][j]=a[aaa];
							aaa++;
						}
					else break;
				}
		for(int i=1;i<=y;i++)
			for(int j=1;j<=x;j++)
				if(b[i][j]==mine && j%2==1)
				{
						cout<<j<<" "<<i;
				}
				else if(b[i][j]==mine && j%2==0)
				{
						cout<<x-j<<" "<<y-i;
				}
		return 0;
}
