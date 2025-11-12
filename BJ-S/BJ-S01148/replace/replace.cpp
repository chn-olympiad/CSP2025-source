#include<iostream>

using namespace std;

const int N = 1e5 + 10;
struct node
{
    string a, b;
}s[N];

int n, q;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> s[i].a >> s[i].b;
    while(q--)
    {
        int ans = 0;
        string t1, t2;
        cin >> t1 >> t2;
        for(int i = 1; i <= n; i++)
        {
            int la = s[i].a.length(), lt = t1.length();
            if(s[i].a.length() > t1.length()) continue;
            for(int j = 0; j < lt - la + 1; j++)
            {
                if(t1.substr(j, la) != s[i].a)
                    continue;
                if(t1.substr(0, j) + s[i].b + t1.substr(j + la) == t2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
