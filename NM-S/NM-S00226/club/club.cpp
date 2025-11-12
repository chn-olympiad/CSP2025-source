#include <bits/stdc++.h>
using namespace std;

struct node
{
    int a;
    int b;
    int c;
    int id;
}s[100005];

bool cmp(node x, node y)
{
    return x.a > y.a;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            s[i].a = 0;
            s[i].b = 0;
            s[i].c = 0;
            s[i].id = i;
        }
        for(int i = 1;i <= n;i++)
        {
            cin >> s[i].a >> s[i].b >> s[i].c;
        }
        if(n == 2)
        {
            int cnt = 0;
            if(s[1].a + s[2].b > cnt)
            {
                cnt = s[1].a + s[2].b;
            }
            if(s[1].a + s[2].c > cnt)
            {
                cnt = s[1].a + s[2].c;
            }
            if(s[1].b + s[2].a > cnt)
            {
                cnt = s[1].b + s[2].a;
            }
            if(s[1].b + s[2].c > cnt)
            {
                cnt = s[1].b + s[2].c;
            }
            if(s[1].c + s[2].a > cnt)
            {
                cnt = s[1].c + s[2].a;
            }
            if(s[1].c + s[2].b > cnt)
            {
                cnt = s[1].c + s[2].b;
            }
            cout << cnt << endl;
        }
        else
        {
            int cnt = 0;
            sort(s + 1, s + n + 1, cmp);
            for(int i = 1;i <= n / 2;i++)
            {
                cnt += s[i].a;
            }
            cout << cnt << endl;
        }

    }
    return 0;
}
