#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    for(int i = 2;i <= n*m;i++)
    {
        if(a[i]>a[1])
        {
            r++;
        }
    }
    if(r%(2*n)!=0 &&r%(2*n)<=n)
    {
        cout <<r/n+1  << " "<< (r%n!=0?r%n:n);
    }
    else
    {
        cout <<r/n+1  << " "<< (r%n!=0?n+1-r%n:1);
    }
}
