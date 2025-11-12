#include<bits/stdc++.h>
#define int long long
#define sc scanf
#define pr printf
#define fr freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
#define w while
#define f(i,x,n,y) for(int i=x;i<=n;i+=y)
#define f_(i,x,n,y) for(int i=x;i>=n;i-=y)
#define st string
using namespace std;
int n,m,a[34896],s[289][325],x,sum=0;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	fr
	cin>>n>>m;
	f(i,1,n*m,1)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	f(i,1,n,1)
	{
		
		if(i%2==1)
		{
			f(j,1,m,1)
			{
				s[j][i]=a[++sum];
			}
		}
		else
		{
			f_(j,m,1,1)
			{
				s[j][i]=a[++sum];
			}	
		}		
	}
	f(i,1,n,1)
	{
		f(j,1,m,1)
		{
			if(s[i][j]==x)
			{
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}

