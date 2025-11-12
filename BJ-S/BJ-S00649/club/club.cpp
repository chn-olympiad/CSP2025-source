#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int N = 1e5 + 5;
int T, n, suma, sumb, sumc, ans;
priority_queue <int, vector <int>, greater <int> > q1, q2, q3;

void solve()
{
    scanf("%d", &n);
    ans = suma = sumb = sumc = 0;
    while(!q1.empty())  q1.pop();
    while(!q2.empty())  q2.pop();
    while(!q3.empty())  q3.pop();
    for(int i = 1, a, b, c;i <= n;i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a >= b && a >= c)
        {
            suma++, ans += a;
            q1.push(a - max(b, c));
        }
        else if(b >= c)
        {
            sumb++, ans += b;
            q2.push(b - max(a, c));
        }
        else
        {
            sumc++, ans += c;
            q3.push(c - max(a, b));
        }
    }
    //printf("%d %d %d %d\n", ans, suma, sumb, sumc);
    if(suma > n / 2)
    {
        while(q1.size() > n / 2)
        {
            ans -= q1.top();
            q1.pop();
        }
    }
    if(sumb > n / 2)
    {
        while(q2.size() > n / 2)
        {
            ans -= q2.top();
            q2.pop();
        }
    }
    if(sumc > n / 2)
    {
        while(q3.size() > n / 2)
        {
            ans -= q3.top();
            q3.pop();
        }
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--)  solve();
    return 0;
}