//GZ-S00346
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

typedef long long ll;

int a[N][10];
int n;
ll sum1 = 0,sum2 = 0,sum3 = 0;
ll tot = 0;

void dfs(int x,int club[])
{
    if(x > n)
    {
        tot = max(tot , sum1 + sum2 + sum3 );
        return ;
    }

    for(int i = 1; i <= 3;i++)
    {
        if(club[i] < (n/2))
        {
            club[i]++;
            if(i == 1)
            {
                sum1 += a[x][i];
                dfs(x+1,club);
                sum1 -= a[x][i];
                club[i] --;
            }else if(i == 2)
            {
                sum2 += a[x][i];
                dfs(x+1,club);
                sum2 -= a[x][i];
                club[i] --;
            }else {
                sum3 += a[x][i];
                dfs(x+1,club);
                sum3 -= a[x][i];
                club[i] --;
            }
        }
    }

    return ;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;

        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                cin >> a[i][j];
            }
        }

        int club[4] = {0,0,0,0};

        sum1 = 0,sum2 = 0,sum3 = 0;
        tot = 0;
        dfs(1,club);
        cout << tot << '\n';
    }

    return 0;
}
