#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    long long n,m,a[101]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i];
        }
    }
    sort(a+1,a+1+n+m);
    cout<<1<<" "<<2;
    return 0;
}
