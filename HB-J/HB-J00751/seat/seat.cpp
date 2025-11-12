#include<bits/stdc++.h>
using namespace std;
int n,m,r,a = 1;
int s[105],zw[15][15];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n * m;i++) cin>>s[i];
    r = s[1];
    sort(s + 1,s + 1 + n * m,greater<int>());
    for(int i = 1;i <= m;i++)
    {
        if(i % 2 == 1)
            for(int j = 1;j <= n;j++)
            {
                zw[j][i] = s[a];
                a++;
            }
        else
            for(int j = n;j > 0;j--)
            {
                zw[j][i] = s[a];
                a++;
            }
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(zw[i][j] == r)
            {
                cout<<j<<" "<<i;
                return 0;
            }
    return 0;
}
