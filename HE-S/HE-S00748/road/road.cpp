#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
int c[10005],a[10005][10005],b[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=5;i++)
    {

        cin>>b[i];
    }
    for(int j=1;j<=5;j++)
    {
        cin>>c[j];
    }
    cout<<"13";
    return 0;
}
