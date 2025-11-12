#include <bits/stdc++.h>

using namespace std;

int n , q;
string a[200010] , b[200010];
string l[200010] , r[200010];
int nxt[200010];


int main()
{
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> a[i] >> b[i];
    }
    for(int i = 1; i <= q; ++ i)
    {
        cin >> l[i] >> r[i];
    }
    for(int i = 1; i <= q; ++ i)
    {
        int ans = 0;
        if(l[i].size() != r[i].size())
        {
            cout << "0\n";
            continue;
        }
        int x , y;
        for(x = 0; x < l[i].size(); ++ x)
        {
            if(l[i][x] != r[i][x]) break;
        }
        for(y = l[i].size() - 1; y >= 0; -- y)
        {
            if(l[i][y] != r[i][y]) break;
        }
        string q = l[i].substr(x , y - x + 1);
        // cout << q << '\n';
        q = "~" + q;
        nxt[1] = 0;
        for(int j = 2 , k = 0; j < q.size(); ++ j)
        {
            while(k && q[j] != q[k + 1]) k = nxt[k];
            if(q[j] == q[k + 1]) k ++;
            nxt[j] = k;
        }
        // for(int i = 1; i <= q.size() - 1; ++ i) cout << nxt[i] << " ";
        // cout << '\n';
        for(int j = 1; j <= n; ++ j)
        {
            for(int jj = 0 , kk = 0; jj < a[j].size(); ++ jj)
            {
                while(kk && a[j][jj] != q[kk + 1]) kk = nxt[kk];
                if(a[j][jj] == q[kk + 1]) kk ++;
                if(kk == q.size() - 1)
                {
                    // cout << j << " "<< kk << " "<< jj - kk + 1 << "\n";
                    // cout << l[i].substr(x - (jj - kk + 1) , a[j].size()) << " "<< a[j] << '\n';
                    if(x - (jj - kk + 1) >= 0 && x - (jj - kk + 1) + a[j].size() <= l[i].size())
                    if(l[i].substr(x - (jj - kk + 1) , a[j].size()) == a[j] && b[j] == r[i].substr(x - (jj - kk + 1) , a[j].size()))
                    {
                        ans ++;
                        break;
                    }
                    // jj - kk + 1
                    kk = nxt[kk];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}