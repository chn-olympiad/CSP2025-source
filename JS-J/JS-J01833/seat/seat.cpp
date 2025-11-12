#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m,xr=0,cj[150];
    cin>>n>>m;
    int b=n*m;
    for (int i=1;i<=b;i++)
    {

        cin>>cj[i];
    }
    xr=cj[1];
    sort(cj+1,cj+b+1,cmp);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (xr==cj[i*j%(b+1)])
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
