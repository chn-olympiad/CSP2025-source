#include <bist/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[109];
    cin>>n>>m;
    for (int i = 1;i<=n*m;i++) cin>>a[i];
    sort (a+1,a+1+n*m);
    for (int i = 1;i<=n*m;i++) cout>>a[i];
    return 0;
}
