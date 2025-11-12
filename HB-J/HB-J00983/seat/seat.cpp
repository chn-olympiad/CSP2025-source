#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int xr=0;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    xr=a[1];
    sort(a+1,a+1+n*m);
    int js=n*m;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[js]==xr)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
                else{
                    js--;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--)
            {
                if(a[js]==xr)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
                else{
                    js--;
                }
            }
        }
    }
    return 0;
}
//happy halloween!
//I'm Kremlin897! luogu:1046158
