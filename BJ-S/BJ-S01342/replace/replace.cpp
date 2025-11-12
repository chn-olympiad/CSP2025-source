#include <fstream>
#include <string>
using namespace std;

const int N = 1001;
string s[N][2], t[N][2];

int main()
{
    ifstream fin;
    fin.open("replace.in");
    ofstream fout;
    fout.open("replace.out");
    int n, q;
    fin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        fin >> s[i][0] >> s[i][1];
    }
    for (int i = 1; i <= q; i++)
    {
        fin >> t[i][0] >> t[i][1];
    }

    if (n <= 1000)
    {
        for (int i = 1; i <= q; i++)
        {
            int ans = 0;
            for (int j = 1; j <= n; j++)
            {
                if (t[i][0].size() < s[j][0].size()) continue;
                for (int x = 0; x <= t[i][0].size() - s[j][0].size(); x++)
                {
                    bool flag = true;
                    for (int y = 0; y < s[j][0].size(); y++)
                    {
                        if (s[j][0][y] != t[i][0][x + y])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        string chk = t[i][0];
                        for (int y = 0; y < s[j][0].size(); y++)
                        {
                            chk[y + x] = s[j][1][y];
                        }
                        if (chk == t[i][1]) ans++;
                    }
                }
            }
            fout << ans << endl;
        }
    }
    return 0;
}
