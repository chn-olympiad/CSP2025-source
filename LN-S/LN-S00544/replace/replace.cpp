#include <iostream>
using namespace std;
string s[200000][2];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> s[i][0] >> s[i][1];
    while (q--)
    {
        int ans = 0;
        string t1, t2;
        cin >> t1 >> t2;
        for (int i = 0; i < n; i++)
            for (int l = 0; l < t1.length(); l++)
                for (int r = l; r < t1.length(); r++)
                    if (r - l + 1 == s[i][0].length())
                    {
                        bool yes = true;
                        for (int j = 0; j < t1.length(); j++)
                            if ((j < l || j > r) && t1[j] != t2[j])
                            {
                                yes = false;
                                break;
                            }
                        for (int j = l; yes && j <= r; j++)
                            if (t1[j] != s[i][0][j - l] || t2[j] != s[i][1][j - l])
                                yes = false;
                        if (yes)
                            ans++;
                    }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
