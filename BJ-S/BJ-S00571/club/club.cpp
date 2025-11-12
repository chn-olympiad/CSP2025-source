#include<bits/stdc++.h>
using namespace std;
int t , n , a[100005][5] , ans;
priority_queue<int , vector<int> , greater<int>> q[5];
int main()
{
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= 3 ; j++)
            {
                cin >> a[i][j];
            }
        }
        while(q[1].size())
        {
            q[1].pop();
        }
        while(q[2].size())
        {
            q[2].pop();
        }
        while(q[3].size())
        {
            q[3].pop();
        }
        ans = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
            {
                ans += a[i][1];
                q[1].push(a[i][1] - max(a[i][2] , a[i][3]));
            }
            else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
            {
                ans += a[i][2];
                q[2].push(a[i][2] - max(a[i][1] , a[i][3]));
            }
            else
            {
                ans += a[i][3];
                q[3].push(a[i][3] - max(a[i][1] , a[i][2]));
            }
        }
        while(q[1].size() > n / 2)
        {
            ans -= q[1].top();
            q[1].pop();
        }
        while(q[2].size() > n / 2)
        {
            ans -= q[2].top();
            q[2].pop();
        }
        while(q[3].size() > n / 2)
        {
            ans -= q[3].top();
            q[3].pop();
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
读题：6

T1 club (100pts)

思考 4

代码 10

对拍 2
*/
