#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int rk=1;
    for(int i=2;i<=n*m;i++)
    {
        if(a[i]>a[1])
            rk++;
    }
    int sj=(rk+n-1)/n,si=(rk+n-1)%n+1;
    if(sj%2==0)
        si=n-si+1;
    cout<<sj<<" "<<si;
    return 0;
}
