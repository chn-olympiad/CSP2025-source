#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==r)
        {
            r=n*m-i+1;
            break;
        }
    }
    if(r%n==0)
    {
         if((r/n)%2==0)
        {
            cout<<r/n<<" "<<1;
        }
        else
        {
            cout<<r/n<<" "<<m;
        }
    }
    else
    {
		if((r/n+1)%2==0)
        {
            cout<<r/n+1<<" "<<m-r%n+1;
        }
       
        else
        {
            cout<<r/n+1<<" "<<r%n;
        }
    }
}
