#include<bits/stdc++.h>
using namespace std;
double n,a[105];
int x,y,m,c;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	y=n*m;
	for(int i=1;i<=y;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+y,cmp);
	for(int i=1;i<=y;i++)
	{
		if(a[i]==x)
		{
			if(i<=n) 
			{
				cout<<1<<" "<<i;
				return 0;
			}
			c=int(ceil(i/n));
			if(c%2==0)
			{
					cout<<ceil(i/n)<<" "<<i%m+1;
			}
			if(c%2!=0)
			{	
				cout<<ceil(i/n)<<" "<<i%m;
			}
		}
		
	}

	return 0;
}

