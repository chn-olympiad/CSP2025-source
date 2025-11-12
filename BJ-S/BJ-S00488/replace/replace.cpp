#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5, P = 1331;
string s, t;
int len[N];
unsigned long long first[N], second[N], pre1[N], pre2[N], pw[N];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
    {
        cin >> s >> t;
        len[i] = s.size();
        for(int j = 0;j < s.size();j++)
            first[i] = first[i] * P + s[j];
        for(int j = 0;j < t.size();j++)
            second[i] = second[i] * P + t[j];
    }
    pw[0] = 1;
    for(int i = 1;i <= 2e3;i++)
        pw[i] = pw[i - 1] * P;
    while(q--)
    {
        cin >> s >> t;
        if(s.size() != t.size())
        {
            cout << 0 << '\n';
            continue;
        }
        s = "#" + s, t = "#" + t;
        for(int i = 1;i < s.size();i++)
            pre1[i] = pre1[i - 1] * P + s[i];
        for(int i = 1;i < t.size();i++)
            pre2[i] = pre2[i - 1] * P + t[i];
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int l = 1;l + len[i] - 1 < s.size();l++)
            {
                int r = l + len[i] - 1;
                if(pre1[r] - pre1[l - 1] * pw[len[i]] == first[i] && pre2[r] - pre2[l - 1] * pw[len[i]] == second[i])
                    if(pre1[s.size() - 1] - first[i] * pw[s.size() - r - 1] + second[i] * pw[s.size() - r - 1] == pre2[t.size() - 1])
                        ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}