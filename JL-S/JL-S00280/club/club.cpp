
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 +7;
int T;
int n;
int a[N][5], b[N][5];
int AAA[N], AA = 0;
bool cmp(int a, int b)
{
    return a > b;
}/**/
int maax(int a, int b, int c)
{
    if(a >= b && a >= c) return a;
    if(b >= a && b >= c) return b;
    if(c >= b && c >= a) return c;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while(T--)
    {
        cin >> n;
        int A = 0, B = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                int x;
                cin >> x;

                b[i][j] = x;
                if(j != 1 && x >= 1)
                {
                    A = 1;
                }
                if (j != 1 && j != 2 && x >= 1)
                {
                    B = 1;
                }
            }

        }

        if(n == 2)
        {
            ll ans = -1;
            for(int i = 1; i <= 3; i++)
            {
                for(int j = 1; j <= 3; j++)
                {
                    if(i != j)
                    {
                        ans = max(ans, 1LL * (b[1][i] + b[2][j]));
                    }
                }
            }
            cout << ans << '\n';
            continue;
        }
        if(n == 4)
        {
            ll ans = -1;
            int ji[4];
            for(int i = 1; i <= 3; i++)
            {
                for(int j = 1; j <= 3; j++)
                {
                    for(int k = 1; k <= 3; k++)
                    {
                        for(int l = 1; l <= 3; l++)
                        {
                            ji[i]++;
                            ji[j]++;
                            ji[k]++;
                            ji[l]++;
                            if(ji[1] <= 2 && ji[2] <= 2 && ji[3] <= 2)
                            {
                                ans = max(ans, 1LL*(b[1][i] + b[2][j] + b[3][k] + b[4][l]));
                            }
                        }
                    }
                }
            }
            cout << ans << '\n';
            continue;
        }
        if(A == 0)
        {
            for(int i = 1; i <= n; i++)
            {
                AAA[++AA] = b[i][1];
            }
            ll ans = 0;
            sort(AAA + 1, AAA + n + 1, cmp);
            for(int i = 1; i <= n / 2; i++)
            {
                ans += AAA[i];
            }
            cout << ans << '\n';
            continue;
        }
        if(B == 0)
        {
            int MAMA[N][2];
            int MIMI[N][2];
            for(int i = 1; i <= n; i++)
            {
                MAMA[i][0] = max(b[i][1], b[i][2]);
                if(MAMA[i][0] == b[i][1])
                {
                    MAMA[i][1] = 1;
                    MIMI[i][0] = b[i][2];
                    MIMI[i][1] = 2;
                }
                else
                {
                    MAMA[i][1] = 2;
                    MIMI[i][0] = b[i][1];
                    MIMI[i][1] = 1;
                }

            }
            priority_queue<int, vector<int>, greater<int> >q;//small 1
            priority_queue<int, vector<int>, greater<int> >p;//small 1
            for(int i = 1; i <= n; i++)
            {
                if(MAMA[i][1] == 1)
                {
                    if(q.size() < n/ 2)
                    {
                        q.push(i);
                    }
                    else
                    {
                        if(MAMA[q.top()][0] < MAMA[i][0])
                        {
                            p.push(q.top());
                            q.pop();
                            q.push(i);
                        }
                        else
                        {
                            p.push(i);
                        }
                    }
                }
                else
                {
                    if(p.size() < n/ 2)
                    {
                        p.push(i);
                    }
                    else
                    {
                        if(MAMA[p.top()][0] < MAMA[i][0])
                        {
                            q.push(p.top());
                            p.pop();
                            p.push(i);
                        }
                        else
                        {
                            q.push(i);
                        }
                    }
                }

            }
            ll ans = 0;
            while(!q.empty())
            {
                ans += q.top();
                q.pop();
            }
            while(!p.empty())
            {
                ans += p.top();
                p.pop();
            }
            cout << ans << '\n';
        }

    }

}
/*
Let me try to think of it.
First, I wanna use the dp.
    I try to build the number club;
    f[i] shows that the i member has been divided
*/
