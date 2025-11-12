#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long s=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
    int c,b,r;
    cin>>n>>m;
    long long u=0;
	s += n*m;
	cout<<s<<endl;
	for(long long i=0;i<=n*m;i++)
	{
		cin>>a[i];
        if(u==0)
        {
            b=a[i];
     	}
    }
    u=0;
    for(long long i=0;i<s;i++)
    {
        for(long long j=i+1;j<s-1;j++)
        {
            if(a[i]>a[j])
            {
                int t=a[i];
                a[i] = a[j];
                a[j] = t;
                cout<<a[i]<<endl;
            }
        }
    }	
	for(long long u=0;u<=n*m;u++)
	{
		if(a[u]==b)
		{
			c=u/n;
			if(c%2==0)
			{
				r=n-u%n;
				break;
			}
			else
			{
				r=u%n;
				break;
			}
		}
	}
    cout<<c<<" "<<r<<endl;
    return 0;
}
