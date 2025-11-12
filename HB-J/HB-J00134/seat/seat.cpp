#include<bits/stdc++.h>
using namespace std;
int m,n,cnt,x,y;
int a[1005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
        if(a[i]>a[1]) cnt++;
    }
    cnt++;
    if(cnt%n==0)x=cnt/n;
    else x=cnt/n+1;
    if(x%2==1)
    {
        y = cnt-(x-1)*n;
    }
    else
    {
        y = x*n-cnt+1;
    }
    cout << x  << " " << y;
    return 0;
}
