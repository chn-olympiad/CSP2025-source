#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[10][100010];
int b[100010];
int c[100010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin >> n;
        int k=n/2;
        int bmax=0;
        for(int j=1;j<=n;j++)
        {
            int x=0;
            for(int h=1;h<=3;h++)
            {
                cin >> a[h][j];
                x=max(x,a[h][j]);
            }
            b[j]=x;
            bmax=max(b[j],bmax);
        }
        sort(b+1,b+1+n);
        int ans=0;
        for(int j=n;j>k;j--)
        {
            ans+=b[j];
        }
        cout << ans << endl;
    }
    return 0;
}
