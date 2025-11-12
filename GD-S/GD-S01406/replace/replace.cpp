#include <iostream>
using namespace std;

int n, m, ls[200005], ds[200005], dt, rt;
string s[2][200005], t[2];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[0][i] >> s[1][i], ls[i] = s[0][i].length();
        for(int j = 0; j < ls[i]; j++)
            if(s[0][i][j] != s[1][i][j])
            {
                ds[i] = j;
                break;
            }
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> t[0] >> t[1];
        int ln = t[0].length(), res = 0;
        dt = -1, rt = ln;
        for(int j = 0; j < ln; j++)
            if(dt == -1 && t[0][j] != t[1][j])
                dt = j;
            else if(dt && t[0][j] == t[1][j])
            {
                rt = j;
                break;
            }
        for(int j = 1; j <= n; j++)
        {
        	/*
            fprintf(stderr, "debug:%d %d %d %d %d %s\n", dt, dt - ds[j], dt - ds[j] + ls[j], rt, ln, s[0][j].data());
            if (dt >= ds[j] && dt - ds[j] + ls[j] >= rt && dt - ds[j] + ls[j] <= ln)
                fprintf(stderr, "debug:%s\n", t[0].substr(dt - ds[j], ls[j]).data());
            */
            if (dt >= ds[j] && dt - ds[j] + ls[j] >= rt && dt - ds[j] + ls[j] <= ln)
                if( s[0][j] == t[0].substr(dt - ds[j], ls[j]) &&
                    s[1][j] == t[1].substr(dt - ds[j], ls[j]))
                    res++;
        }
        cout << res << endl;
    }
    return 0;
}
