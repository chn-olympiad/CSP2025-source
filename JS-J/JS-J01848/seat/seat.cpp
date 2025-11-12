#include<bits/stdc++.h>
using namespace std;
int n,m,a[111],cnt=0,ans=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>=a[1])
        {
            cnt++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans++;
            if(ans==cnt)
            {
                cout<<i;
                putchar(' ');
                if(i%2==1)
                {
                    cout<<j;
                    return 0;
                }
                else
                {
                    cout<<n-j+1;
                    return 0;
                }
            }
        }
    }
    return 0;
}
