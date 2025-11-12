#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
struct node
{
    int id,data,x,y;
}a[N];
int n,m;
int g[1010][1010];
bool cmp(node x,node y)
{
    return x.data>y.data;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) 
    {
        cin>>a[i].data;
        a[i].id=i;
    }
    sort(a+1,a+1+m*n,cmp);
    int x=1,y=1,d=1;
    for(int s=1;s<=n*m;s++)
    {
        g[x][y]=a[s].data;
        a[s].x=x;a[s].y=y;
        x+=d;
        if(x>n)
        {
            x=n;
            y++;
            d*=-1;
        }
        if(x<1)
        {
            x=1;
            y++;
            d*=-1;
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].id==1)
        {
            cout<<a[i].y<<" "<<a[i].x<<'\n';
            return 0;
        }
    }
    return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/