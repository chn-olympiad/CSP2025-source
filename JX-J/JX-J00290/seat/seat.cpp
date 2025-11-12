#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int mod=1e9+7;
int a[105];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int cur=a[1];
    sort(a+1,a+(n*m)+1,greater<int>());
    for(int j=1;j<=m;j++)
    {
        if(j%2)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[(j-1)*n+i]==cur)
                {
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }
        else
        {
            for(int i=n;i>=1;i--)
            {
                if(a[(j-1)*n+i]==cur)
                {
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }

    }
    return 0;
}
