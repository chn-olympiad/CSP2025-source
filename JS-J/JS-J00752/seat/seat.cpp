#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
int a[N];
int b[15][15];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int k=a[1];
    sort(a+1,a+n*m+1,cmp);
    int x=1,y=1,f=1;
    for(int i=1;i<=n*m;i++)
    {
        b[x][y]=a[i];
        x+=f;
        if(x==n+1) x=n,y++,f=-f;
        if(x==0) x=1,y++,f=-f;
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //         cout<<b[i][j]<<" ";
    //     cout<<"\n";
    // }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(b[i][j]==k)
            {
                cout<<j<<" "<<i<<"\n";
                return 0;
            }
    return 0;
}