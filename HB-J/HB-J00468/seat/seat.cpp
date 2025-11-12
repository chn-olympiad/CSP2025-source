#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[105],cnt=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i];
        if(a[i]>a[1])
        {
            cnt++;
        }
    }
    cout << (cnt+n-1)/n << ' ';
    if(((cnt+n-1)/n)%2==1)
    {
        cout << (cnt-1)%n+1;
        return 0;
    }
    else
    {
        cout << n-(cnt-1)%n;
        return 0;
    }
    return 0;
}
