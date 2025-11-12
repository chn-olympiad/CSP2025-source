#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n*m;i++)
        cin >>a[i];
    int x=a[1],y;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
        if(a[i]==x)
        {
            y=i;
            break;
        }
    if(y%n==0)
    {
        if((y/n)%2==0)
            cout <<y/n<<" "<<"1";
        else
            cout <<y/n<<" "<<"n";
    }
    else
    {
        int o=y/n+1,p=y%n;
        if(o%2==0)
            cout <<o<<" "<<n-p+1;
        else
            cout <<o<<" "<<p;
    }
    return 0;
}
