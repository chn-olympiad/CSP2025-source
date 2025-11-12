#include <bits/stdc++.h>
using namespace std;

int s[105];
int mp[15][15];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n*m;i++)
    {
        cin>>s[i];
    }

    int k=s[1];

    sort(s+1,s+n*m+1,greater<int>());

    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                mp[j][i]=s[(i-1)*m+j];
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                mp[j][i]=s[(i-1)*m+n-j+1];
            }
        }
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mp[i][j]==k)
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }

    return 0;
}
