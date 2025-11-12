#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],num,xx,yy,b;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)
		{
			xx=i/n;
			if(i%n==0)
				b=n;
			else
			{
				xx++;
				b=i%n;
			}
			if(xx%2==1)
				yy=b;
			else
				yy=n+1-b;
			break;
		}
	}
	cout<<xx<<" "<<yy;
	return 0;
}
