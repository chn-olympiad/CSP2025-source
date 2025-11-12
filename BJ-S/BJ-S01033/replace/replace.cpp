#include <bits/stdc++.h>

using namespace std;

int n,q;
string plc1[210], plc2[210];


int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;

    for(int i = 1; i <= n; i++)
    {
        cin >> plc1[i] >> plc2[i];
    }

    for(int i = 1; i <= q; i++)
    {
        long long ans = 0;
        string l1, l2;
        cin >> l1 >> l2;
        for(int j = 0; j < l1.size(); j++)
        {
            for(int p = 1; p <= n; p++)
            {
                string s = "";
                int siz = s.size();
                while(plc1[p][siz] == l1[j] && siz <= plc1[p].size()) s += plc1[p][siz], siz = s.size();
                if(s != plc1[p]) continue;
                else
                {
                    string now = "";
                    for(int w = 0; w < j; w++)
                    {
                        now += l1[w];
                    }
                    now += s;
                    for(int w = j + s.size(); w < l1.size(); w++)
                    {
                        now += l1[w];
                    }

                    if(now == l2) ans += 1;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
