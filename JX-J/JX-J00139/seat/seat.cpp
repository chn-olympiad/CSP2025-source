#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1010],cur;
void input()
{
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
            cur=a[i];
    }
}
void solution()
{
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
                if(a[(i-1)*n+j]==cur)
                {
                    if(i%2==1)
                    {
                        cout<<i<<' '<<j;
                    }
                    else
                    {
                        cout<<i<<' '<<m-j+1;
                    }
                    return ;
                }
        }
    }
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    solution();
    return 0;
}
