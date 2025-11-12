#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[10005][10005],s,n;
    cin>>s>>n;
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int o=1;o<=100;o++)
    {
        for(int i=1;i<=s;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=max(a[i][j],a[i][j+1]);
            }
        }
    }

}
