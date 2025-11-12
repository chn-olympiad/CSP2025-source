#include <bits/stdc++.h>
using namespace std;
int a[120];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i*m+j];

    int r=a[0];

    sort(a,a+n*m);
    int pos=lower_bound(a,a+n*m,r)-a;

    pos=n*m-pos-1;

    // cout<<pos<<'\n';
    cout<<pos/n+1<<' '<<(pos/n&1 ? n-pos%n : pos%n+1)<<'\n';

    return 0;
}