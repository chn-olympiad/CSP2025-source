#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    
    int n,m,a[100010],b[100010],cnt=0,t=0;
    cin>>n>>m;
    t=n*m;
    for(int i=0;i<t;i++)
    {
		cin>>a[i];
		b[i]=a[i];
	}
    sort(b,b+t);
    for(int i=0;i<t;i++)
    {
		if(a[0]==b[i]) cnt=t-i;
	}
	for(int i=1;;i++)
	{
		if(i*n==cnt)
		{
			if(i%2==0)
			{
				cout<<i<<" "<<"1"<<" ";
				break;
			}
			else 
			{
				cout<<i<<" "<<n<<" ";
				break;
			}
		}
		else if(i*n-cnt>0 and i*n-cnt<n)
		{
			if(i%2==0)
			{
				cout<<i<<" "<<i*n-cnt+1<<" ";
				break;
			}
			else
			{
				cout<<i<<" "<<cnt-(i-1)*n<<" ";
				break;
			}
		}
	}
    return 0;
}
