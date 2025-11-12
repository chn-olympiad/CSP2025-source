#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[3][100005];
int cnt[3];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdin);
    long long ans = 0;
    queue<int> q;
    scanf("%d", &t);
    int mx[3];
    for(int i=1; i<=t; i++)
    {
        scanf("%d", &n);
        for(int k=1; k<=3; k++)
        {
            for(int j=1; j<=n; j++)
                cin >> a[k][j];
        }
        for(int k=1; k<3; k++)
        {
            while(cnt[k]<n){
                for(int j=2; j<=n; j++)
                {
                    if(a[k][j]<a[k][j-1])
                    {
                        mx[k] = a[k][j-1];
                    }
                    else
                    {
                        mx[k] = a[k][j];
                    }
                    ans += mx[k];
                    cnt[k]++;
                }
            }
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
