#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000000];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)cin>>a[i];
    int num=a[0];
    sort(a,a+n*m,[](int a,int b){return a>b;});
    for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)if(a[(j-1)*n+i-1]==num)
    {
        cout<<j<<" ";
        if(j%2==1)cout<<i;
        else cout<<n-i+1;
        return 0;
    }
    return 0;
}
