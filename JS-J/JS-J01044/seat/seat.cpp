#include<bits/stdc++.h>
using namespace std;
int	x,y,n,m,tp,a[105];
bool cmp(int x1,int y2)
{
	return x1>y2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
			tp=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int j=1;
	x=1;
	y=1; 
	while(a[j]!=tp)
	{
		if(j%(2*n)>=1&&j%(2*n)<n)
			y++;
		else
		{
			if(j%(2*n)>n&&j%(2*n)<2*n)
				y--;
			else
				x++;
		}
		j++;
	}
	cout<<x<<" "<<y;
	return 0;
}
