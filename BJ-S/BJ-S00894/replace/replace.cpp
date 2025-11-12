#include<bits/stdc++.h>
using namespace std;
const int N = int(2e5) + 10;
string s[N], t[N];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> s[i] >> t[i];
    while(q--)
    {
        string x, y;
        cin >> x >> y;
        int m = int(x.length()), res = 0;
        for(int i = 0; i < m; i++)
        {
            string tmp;
            for(int j = i; j < m; j++)
            {
                tmp += x[j];
                for(int k = 1; k <= n; k++)
                {
                    if(tmp != s[k]) continue;
                    string z;
                    for(int l = 0; l < i; l++) z += x[l];
                    z += t[k];
                    for(int l = j + 1; l < m; l++) z += x[l];
                    if(z == y) res++;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}