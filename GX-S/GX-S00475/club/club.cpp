#include<bits/stdc++.h>
using namespace std;

int a[100005][5];

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,ans = 0;
        cin>>n;
        for(int i = 1;i <= n;i++)
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        int ans2 = ans;
        for(int i = 1;i <= 3;i++)
        {
            for(int j = 1;j <= 3;j++)
            {
                if(i == j)
                    continue;
                ans = a[1][i] + a[2][j];
                if(ans > ans2)
                {
                    ans2 = ans;
                    ans = 0;
                }
            }

        }
        cout<<ans2<<endl;
    }
    return 0;
}
