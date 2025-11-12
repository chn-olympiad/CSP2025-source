#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],b[110][110],k;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
    {
        cin>>a[i];
    }
    int id=a[1];
    int nm=n*m;
    sort(a+1,a+1+nm,cmp);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(id==a[++k])
            {
                cout<<i<<" "<<j<<"\n";
            }
        }
    }

    return 0;
}