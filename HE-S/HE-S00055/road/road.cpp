#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1000000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    if(k==0)
    {
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin >> x >> y >> a[i];
        }
        sort(a+1,a+1+m);
        int ans=0;
        for(int i=1;i<=n-1;i++)
        {
            ans+=a[i];
        }
        cout << ans;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
