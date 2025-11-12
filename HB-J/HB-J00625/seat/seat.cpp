#include<bits/stdc++.h>
using namespace std;
int b[110],k;
bool s(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[15][15],jg=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    int x=b[1];
    sort(b+1,b+n*m+1,s);
    for(int i=1;i<=m;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<=n;j++)
            {
                a[i][j]=b[jg++];
            }
        }
    }
    return 0;
}
