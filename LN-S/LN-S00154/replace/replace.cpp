#include<iostream>
#include<unordered_map>
#define endl '\n'
using namespace std;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    unordered_map<string, string> ma;
    for(int i = 1; i <=n; i ++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        ma[s1] = s2;
    }
    while(q--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int ans = 0;
        for(auto it = ma.begin(); it != ma.end(); ++it)
        {
            int pos = 0;
            while(pos != string::npos)
            {
                pos = s1.find(it->first, pos);
                if(pos == string::npos)
                    break;
                string cp = s1;
                cp = cp.replace(pos, it->first.size(), it->second);
                //cout << cp << endl;
                if(cp == s2)
                    ans ++;
                pos ++;
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
