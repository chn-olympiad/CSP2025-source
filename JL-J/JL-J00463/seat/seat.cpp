#include <bits/stdc++.h>
using namespace std;
int m,n,a[110],cnt=1,r,h,l;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>r)
            cnt++;
    }

    if(cnt%n==0)
        l=cnt/n;
    else
        l=cnt/n+1;
    if(l%2==0)
        h=n-(cnt%n)+1;
    else if(cnt%n==0)
        h=cnt;
    else
        h=cnt%n;
    cout<<l<<" "<<h;
    return 0;
}
