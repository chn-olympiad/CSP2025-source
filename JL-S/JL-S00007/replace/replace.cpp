// C
// expect pts = 10 ~ 25
// expect diff =

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int n, m;
string repl[maxn], repr[maxn];

bool check(int l, int r, string q, string need)
{
    //replace a的起始点，换几个字符，换成什么
    int len = r-l+1;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(repl[i].size() == len && q.substr(l, len) == repl[i])
        {
            string qq = q;
            qq.replace(l, len, repr[i]);
            if(qq == need)
                return 1;
        }
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
        cin >> repl[i] >> repr[i];


    while(m --)
    {
        string ql, qr;
        cin >> ql >> qr;

        int len = ql.size();
        int ans = 0;
        for(int r = 0 ; r < len ; r ++)
            for(int l = 0 ; l <= r ; l ++)
                if(check(l, r, ql, qr))
                    ans ++;

        cout << ans << endl;
    }
}
