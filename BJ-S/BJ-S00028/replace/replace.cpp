#include <iostream>
using namespace std;
const int N = 2e5 + 5;
string s[N][2];

void work(string& a, string& b)
{
    int l = 0, r = a.size() - 1;
    while (a[l] == b[l] && l != a.size() - 1) l++;
    while (a[r] == b[r] && r != 0) r--;
    if (l > r) a = "", b = "";
    else
    {
        a = a.substr(l, r - l + 1);
        b = b.substr(l, r - l + 1);
    }
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i][0] >> s[i][1];
        /*
        int l = 0, r = s.size() - 1;
        while (s[i][0][l] == s[i][1][l] && l != n) l++;
        while (s[i][0][r] == s[i][1][r] && r != 0) r--;
        if (l < r) s[i][0] = "", s[i][1] = "";
        else
        {
            s[i][0][l] = s[i][0][l].substr(l, r - l + 1);
            s[i][1][l] = s[i][1][l].substr(l, r - l + 1);
        }
        */
        // work(s[i][0], s[i][1]);

    }
    while (q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        int mn = -1, mx;
        for (int i = 0; i < t1.size(); i++)
        {
            if (t1[i] != t2[i])
            {
                //cout << "yes\n";
                if (mn == -1) mn = i;
                mx = i;
            }
        }
        // cout << mn << "\n";
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int n = s[i][0].size();

            for (int j = max(0, mx - n + 1); j <= min(n - 1, mn); j++)
            {
                cout << j << "&\n";
                if (t1.substr(j, j + n - 1) == s[i][0].substr(j, j + n - 1) && t2.substr(j, j + n - 1) == s[i][1].substr(j, j + n - 1)) {
                    //cout << i << " " << j << endl;
                    ans++;}
            }
        }
        cout << ans << endl;
    }


    /*while(q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        work(t1, t2);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (t1 == s[i][0] && t2 == s[i][1]) ans++;
        }
        cout << ans << endl;
    }

    string a = "trash", b = "tllsl";
    work(a, b);
    cout << a << "&" <<b << endl;
    */
    return 0;
}
