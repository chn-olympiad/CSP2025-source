#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int x1 , x2 , id1 , id2;
    bool operator < (const node &qwq) const
    {
        return x1 > qwq.x1;
    }
}e[100010];
struct node2
{
    int x , id;
    bool operator < (const node2 &qwq) const
    {
        return x > qwq.x;
    }
};
int n , num[4];
void solve()
{
    scanf("%lld" , &n);
    for(int i = 1 , a , b , c ; i <= n ; i ++)
    {
        scanf("%lld%lld%lld" , &a , &b , &c);
        e[i].x1 = max({a , b , c});
        if(e[i].x1 == a)
        {
            e[i].id1 = 1;
            if(b > c) e[i].x2 = b , e[i].id2 = 2;
            else e[i].x2 = c , e[i].id2 = 3;
        }
        if(e[i].x1 == b)
        {
            e[i].id1 = 2;
            if(a > c) e[i].x2 = a , e[i].id2 = 1;
            else e[i].x2 = c , e[i].id2 = 3;
        }
        if(e[i].x1 == c)
        {
            e[i].id1 = 3;
            if(b > a) e[i].x2 = b , e[i].id2 = 2;
            else e[i].x2 = a , e[i].id2 = 1;
        }
    }
    sort(e + 1 , e + n + 1);
    priority_queue<node2> q1 , q2 , q3;
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(num[e[i].id1] == n / 2)
        {
            ans += e[i].x1;
            if(e[i].id1 == 1)
            {
                q1.push({e[i].x1 - e[i].x2 , e[i].id2});
                node2 tmp = q1.top();
                ans -= tmp.x;
                q1.pop();
                num[tmp.id] ++;
            }
            if(e[i].id1 == 2)
            {
                q2.push({e[i].x1 - e[i].x2 , e[i].id2});
                node2 tmp = q2.top();
                ans -= tmp.x;
                q2.pop();
                num[tmp.id] ++;
            }
            if(e[i].id1 == 3)
            {
                q3.push({e[i].x1 - e[i].x2 , e[i].id2});
                node2 tmp = q3.top();
                ans -= tmp.x;
                q3.pop();
                num[tmp.id] ++;
            }
            // num[e[i].id2] ++;
            // ans += e[i].x2;
        }
        else
        {
            num[e[i].id1] ++;
            ans += e[i].x1;
            if(e[i].id1 == 1) q1.push({e[i].x1 - e[i].x2 , e[i].id2});
            if(e[i].id1 == 2) q2.push({e[i].x1 - e[i].x2 , e[i].id2});
            if(e[i].id1 == 3) q3.push({e[i].x1 - e[i].x2 , e[i].id2});
        }
    }
    printf("%lld\n" , ans);
    for(int i = 1 ; i <= n ; i ++) e[i].x1 = e[i].x2 = e[i].id1 = e[i].id2; 
    num[1] = num[2] = num[3] = 0;
}
signed main()
{
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    int t; scanf("%lld" , &t);
    while(t --) solve();
    return 0;
}