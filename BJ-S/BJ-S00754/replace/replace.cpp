#include <iostream>
using namespace std;

const int N = 5e6;
int n, q, border1[N * 2 + 5], border2[N * 2 + 5];
string str1, str2;

int main()
{
    // 写 freopen!
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        str1 += "#" + s1;
        str2 += "#" + s2;
    }

    while (q--)
    {
        string t1, t2, s1 = " ", s2 = " ";
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << 0 << endl;
            continue;
        }
        else if (t1 == t2)
        {
            cout << n << endl;
            continue;
        }

        int p1 = 0, p2 = t1.size() - 1;
        while (p1 <= p2 && t1[p1] == t2[p1]) ++p1;
        while (p2 >= p1 && t1[p2] == t2[p2]) --p2;
        for (int i = p1; i <= p2; ++i)
        {
            s1.push_back(t1[i]);
            s2.push_back(t2[i]);
        }
        s1 += str1;
        s2 += str2;

        // cout << s1 << endl << s2 << endl;
        long long ans = 0;
        border1[1] = border2[1] = 0;
        for (int i = 2; i < s1.size(); ++i)
        {
            border1[i] = border2[i] = 0;
            if (s1[i] == '#') continue;
            int j1 = border1[i - 1];
            int j2 = border2[i - 1];
            while (j1 && s1[j1 + 1] != s1[i]) j1 = border1[j1];
            if (s1[j1 + 1] == s1[i]) border1[i] = j1 + 1;
            while (j2 && s2[j2 + 1] != s2[i]) j2 = border2[j2];
            if (s2[j2 + 1] == s2[i]) border2[i] = j2 + 1;
            if (border1[i] >= p2 - p1 + 1 && border2[i] >= p2 - p1 + 1) ++ans;
            // cout << s1[i] << ": " << border1[i] << " " << border2[i] << endl;
        }

        cout << ans << endl;
    }

    return 0;
}