#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ans[15][15],cnt,r=1,c=1,p,v;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    p=a[1],v=1;
    sort(a+1,a+111,greater<int>());
    while(r<=n&&c<=m)
    {
        ans[r][c]=a[++cnt];
        if(v%2) c++;
        else c--;
        if(c>n) c=n,r++,v++;
        if(c<1) c=1,r++,v++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ans[i][j]==p)
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}