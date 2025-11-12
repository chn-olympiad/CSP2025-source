#include<iostream>
#include<algorithm>
using namespace std;
int n,m,R,a[105],x,y;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stduot);
    cin>>n>>m>>R;
    a[1]=R;
    for(int i=2;i<=n*m;i++)
    {
        cin>>x;
        a[i]=x;
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==R)
        {
            R=i;
        }
    }
    x=R/n;
    y=R%n;
    if(y==0)
	{
		y=n;
		x-=1;
	}
    if(x%2==1)
    {	
        cout<<x<<' '<<y;
    }
    else
    {
        cout<<x<<' '<<n-y-1;
	}
    return 0;
}
