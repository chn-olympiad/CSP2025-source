#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int b[100005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    int r=b[1];
    sort(b+1,b+n*m,cmp);
    long long k=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=b[k];
            k++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==r)
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
