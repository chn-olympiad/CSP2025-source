#include<bits/stdc++.h>
using namespace std;
const int N = 110,M = 15; 

int n,m,a[N],mp[M][M],b;
bool cmp(int x,int y)
{
	return x>y;
}
void d(int x,int y)
{
	for(int i=1;i<=n*m;i++)
	{
		mp[x][y]=a[i];
		if(mp[x][y]==b)
		{
			cout<<y<<" "<<x;
			return;
		}
		
		if(y%2==1)
		{
			if(x<n)
			{
				++x;
			}
			else
			{
				++y;
			}
		}
		else
		{
			if(x>1)
			{
				--x;
			}
			else
			{
				++y;
			}
		}
		
	}	
	
}
int main()
{
//注意freopen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;

	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		if(i==1) b=a[i];
	}
	
	sort(a+1,a+k+1,cmp);
	
	d( 1 , 1 );
	return 0;
 } 