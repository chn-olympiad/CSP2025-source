#include <bits/stdc++.h>
using namespace std;
string s[100005], ss[100005];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n;i++)
    {
        cin >> s[i] >> ss[i];
    }
    while(q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        int cnt = t1.size(), cnt2 = t2.size();
        if(cnt != cnt2)
        {
            cout << "0" << endl;
            continue;
        }
        t1 = '0' + t1;
        t2 = '0' + t2;
        int ls = 1, rs = cnt;
        while(t1[ls] == t2[ls]) ls++;
        while(t1[rs] == t2[rs]) rs--;
        int ans = 0;
        string u = t1.substr(ls, rs - ls + 1);
        //cout << u << endl;
        for(int i = 1; i <= n;i++)
        {
            int op = t1.find(s[i]);
            if(!(0 <= op && op < cnt)) continue;
            //cout <<"1" << endl;
            for(int j = rs - ls; j < s[i].size();j++)
            {
                string k = s[i].substr(j - (rs - ls), (rs - ls + 1));
               // cout << k << endl;
                if(k == u)
                {
                    string y = t1.substr(1, ls - j + (rs - ls) - 1), z = t1.substr(rs + (s[i].size()) - j);
                    string repa = "0" + y + ss[i] + z;
                   // cout << repa << " " << t2 << endl;
                    if(repa == t2) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
