#include <bits/stdc++.h>
using namespace std;
int p[105],n,m,o,u,l;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>p[i];
    u=p[1];
    sort(p+1,p+n*m+1);
    for(int i=m*n;i>=1;i--)
    {
        l++;
        if(p[i]==u)
        {
            o=l;
            break;
        }
    }
    if((o+n-1)/n%2==1)
    {
        cout<<(o+n-1)/n<<' ';
        if(o%n!=0)
            cout<<o%n;
        else
            cout<<n;
        return 0;
    }
        else
    {
        cout<<(o+n-1)/n<<' ';
        if(o%n!=0)
            cout<<abs(o%n-n)+1;
        else
            cout<<n;
        return 0;
    }
}
