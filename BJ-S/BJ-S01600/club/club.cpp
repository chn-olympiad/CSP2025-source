#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[4][N], cnt[4];
priority_queue <int, vector <int>, greater <int> > q[4];
void Memset()
{
    while(!q[1].empty())
        q[1].pop();
    while(!q[2].empty())
        q[2].pop();
    while(!q[3].empty())
        q[3].pop();
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(cnt, 0, sizeof(cnt));
        Memset();
        int n;
        cin >> n;
        int max1 = n / 2, sum1 = 0;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[1][i] >> a[2][i] >> a[3][i];
            int max2 = max(a[1][i], max(a[2][i], a[3][i]));
            if(max2 == a[1][i])
                cnt[1]++, q[1].push(a[1][i] - max(a[2][i], a[3][i])), sum1 += a[1][i];
            else if(max2 == a[2][i])
                cnt[2]++, q[2].push(a[2][i] - max(a[1][i], a[3][i])), sum1 += a[2][i];
            else
                cnt[3]++, q[3].push(a[3][i] - max(a[2][i], a[1][i])), sum1 += a[3][i];
        }
        if(cnt[1] > max1)
        {
            while(cnt[1] > max1)
            {
                sum1 -= q[1].top();
                q[1].pop();
                cnt[1]--;
            }
        }
        else if(cnt[2] > max1)
        {
            while(cnt[2] > max1)
            {
                sum1 -= q[2].top();
                q[2].pop();
                cnt[2]--;
            }
        }
        else if(cnt[3] > max1)
        {
            while(cnt[3] > max1)
            {
                sum1 -= q[3].top();
                q[3].pop();
                cnt[3]--;
            }
        }
        cout << sum1 << endl;
    }
    return 0;
}