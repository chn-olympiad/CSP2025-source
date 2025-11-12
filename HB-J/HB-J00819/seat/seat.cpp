#include<bits/stdc++.h>
using namespace std;
bool pd(int a,int b)
{   return a>b;
}
int main()
{   freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,g;
    cin>>n>>m;
    int a[n*m+1];
    for(int i=1;i<=n*m;i++)
    {   cin>>a[i];
    }
    int h=a[1];
    sort(a+1,a+n*m+1,pd);
    for(int i=n*m;i>=1;i--)
        if(a[i]==h)
        {   g=i;
            break;
        }
    if(g%n==0)
    {   int s=g/n;
        if(s%2==0)
            cout<<s<<" "<<1;
        else
            cout<<s<<" "<<n;
    }
    else
    {   int s=g/n+1;
        int m=g%n;
        if(s%2==0)
            cout<<s<<" "<<n-m+1;
        else
            cout<<s<<" "<<m;
    }
    return 0;
}
