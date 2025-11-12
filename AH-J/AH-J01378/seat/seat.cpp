#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>=a[1])a[0]++;
    }
    int x=(a[0]-1)/n+1,y;
    if(x&1)
    {
        y=n-x*n+a[0];
    }
    else
    {
        y=x*n-a[0]+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
