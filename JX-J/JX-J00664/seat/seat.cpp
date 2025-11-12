#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int a[N];
int main()
{
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)cin>>a[i];
    int res=a[1],cnt;
    sort(a+1,a+n*m+1,greater<int>());
    for (int i=1;i<=n*m;i++)
        if (a[i]==res)
        {
            cnt=i;
            break;
        }
    int a=(cnt+n-1)/n,b;
    if (a%2==1)
    {
        b=cnt%n;
        if (b==0)b=n;
    }
    else
    {
        int x=cnt%n;
        if (x==0)x=n;
        b=n+1-x;
    }
    cout<<a<<' '<<b<<endl;
    return 0;
}
