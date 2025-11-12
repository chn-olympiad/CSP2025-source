#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,sp,ln,cl;
const int N=514;
int a[N],mp[N][N];
bool cmp(int a,int b)
{
    return a>b;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int sz=n*m;
    for(int i=1;i<=sz;i++)
    {
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+1+(sz),cmp);
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)//jishuhang
        {
            for(int j=1;j<=m;j++)
            {
                mp[i][j]=a[(i*m)+j-1];
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                mp[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==x)
            {
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}
