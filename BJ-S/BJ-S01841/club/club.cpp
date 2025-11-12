#include <bits/stdc++.h>
using namespace std;
int t,number;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        int a[200005][5];
        memset(a, 0, sizeof a);
        int num[5] = {0};
        long long ans = 0;
        int number = 0;
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=3; j++)
            {
                cin >> a[i][j];
            }
        }
        bool flag = false;
        while(flag == false)
        {
            int maxx = 0;
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=3; j++)
                {
                    maxx = max(maxx, a[i][j]);
                }
            }
            for(int i=1; i<=n; i++)
            {
                bool flag1 = false;
                for(int j=1; j<=3; j++)
                {
                    if(a[i][j] == maxx && num[j] <= n/2 && flag1==false)
                    {
                        flag = true;
                        ans += a[i][j];
                        a[i][j] = -1;
                        number++;
                        num[j]++;
                        if(number >= n && flag == false)
                        {
                            cout << ans;
                            flag = true;
                        }
                    }
                }
            }
            /*
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=3; j++)
                {
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
            */
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}