#include<bits/stdc++.h>
#define ll long long
#define mp(i, j) make_pair(i, j)
#define pii pair<int, int>
using namespace std;
int t;
int n;
ll ans;
struct node
{
    int num[4];
    int _ma, _mai, _cma, _cmai, _la, _lai;
    int ma()
    {
        return _ma;
    }
    node()
    {
        num[0] = num[1] = num[2] = 0;
        num[3] = 0;
    }
    void init()
    {
        int ind = 0, c = 3;
        for(int i = 1; i < 3; i ++)
        {
            if(num[i] > num[ind])
            {
                // c = ind;
                ind = i;
            }
        }
        for(int i = 0; i < 3; i ++)
        {
            if(i == ind) continue;
            if(num[c] < num[i])
            {
                c = i;
            }
        }
        _ma = num[ind], _mai = ind;
        _cma = num[c], _cmai = c;
        for(int i = 0; i < 3; i ++)
        {
            if(i != c && i != ind)
            {
                _la = num[i];
                _lai = i;
                break;
            }
        }
    }
    int mai()
    {
        
        return _mai;
    }
    int cma()
    {
        return _cma;
    }
    int cmai()
    {
        return _cmai;
    }
    int la()
    {
        return _la;
    }
}a[100005];
bool cmp(node a, node b)
{
    return a.ma() > b.ma();
}
struct cmp_pii
{
    bool operator()(pii _a, pii b)
    {
        if(_a.first != b.first) return _a.first > b.first;
        else
        {
            return a[_a.second].cma() - a[_a.second].ma() > a[b.second].cma() - a[b.second].ma();
            // if(a[_a.second].cma() != a[b.second].cma())
            // {
            //     return a[_a.second].cma() > a[b.second].cma();
            // }
            // return a[_a.second].la() > a[b.second].la();
        }
    }
};
priority_queue<pii, vector<pii>, greater<pii> > p[3];
int main()
{
    // freopen("../sub/club/club5.in", "r", stdin);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while(t --)
    {
        ans = 0;
        for(int i = 0; i < 3; i ++)
        {
            while(!p[i].empty())
            {
                p[i].pop();
            }
        }
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d%d%d", &a[i].num[0], &a[i].num[1], &a[i].num[2]);
            a[i].init();
            // printf("%d %d %d\n", a[i].mai(), a[i].cmai(), a[i]._lai);
        }
        // sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= n; i ++)
        {
            if(p[a[i].mai()].size() == n / 2)
            {
                pii c = p[a[i].mai()].top();
                if(a[i].ma() - c.first > a[i].cma())
                {
                    // printf("1\n");
                    ans += a[i].ma() - c.first;
                    p[a[i].mai()].pop();
                    p[a[c.second].cmai()].push(mp(a[c.second].cma() - a[c.second].la(), c.second));
                    p[a[i].mai()].push(mp(a[i].ma() - a[i].cma(), i));
                }
                else
                {
                    p[a[i].cmai()].push(mp(a[i].cma() - a[i].la(), i));
                    ans += a[i].cma();
                }
            }
            else
            {
                p[a[i].mai()].push(mp(a[i].ma() - a[i].cma(), i));
                ans += a[i].ma();
            }
        }
        printf("%lld\n", ans);
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}