#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a;
    cin>>a;
    int cnt=1;
    for (int i=2;i<=n*m;i++)
    {
       int b;
       cin>>b;
       if (b>a)
       {
           cnt++;
       }
    }
    int c;
    c=cnt/n-1;
    if (cnt%n!=0)
    {
        c++;
    }
    if ((c+1)%2==1)
    {
        cout<<c+1<<" "<<cnt-c*n;
    }
    else
    {
        cout<<c+1<<" "<<n-(cnt-c*n)+1;
    }
    return 0;
}
