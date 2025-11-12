#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100001;
struct mbr
{
    int love[3][2];
};
mbr mems[N];
int lmax[3];

bool comp(mbr x1, mbr x2)
{
    return x1.love[0][0] - x1.love[1][0] > x2.love[0][0] - x2.love[1][0];
}

mbr crt(int a, int b, int c, int d, int e, int f)
{
    mbr z;
    z.love[0][0] = a;
    z.love[0][1] = b;
    z.love[1][0] = c;
    z.love[1][1] = d;
    z.love[2][0] = e;
    z.love[2][1] = f;
    return z;
}

void newmbr(int a, int b, int c, int i)
{
    if (a >= b && b >= c) mems[i] = crt(a, 0, b, 1, c, 2);
    else if (a >= c && c >= b) mems[i] = crt(a, 0, c, 2, b, 1);
    else if (b >= a && a >= c) mems[i] = crt(b, 1, a, 0, c, 2);
    else if (b >= c && c >= a) mems[i] = crt(b, 1, c, 2, a, 0);
    else if (c >= a && a >= b) mems[i] = crt(c, 2, a, 0, b, 1);
    else mems[i] = crt(c, 2, b, 1, a, 0);
}

int main()
{
    ifstream fin;
    fin.open("club.in");
    ofstream fout;
    fout.open("club.out");
    int t;
    fin >> t;
    while (t--)
    {
        memset(lmax, 0, sizeof(lmax));
        int n, ans = 0;
        fin >> n;
        for (int i = 1; i <= n; i++)
        {
            int a, b, c;
            fin >> a >> b >> c;
            newmbr(a, b, c, i);
            lmax[mems[i].love[0][1]]++;
        }
        if (lmax[0] <= n / 2 && lmax[1] <= n / 2 && lmax[2] <= n / 2)
        {
            for (int i = 1; i <= n; i++)
            {
                ans += mems[i].love[0][0];
            }
            fout << ans << endl;
            continue;
        }
        int maxc;
        if (lmax[0] >= lmax[1] && lmax[0] >= lmax[2]) maxc = 0;
        else if (lmax[1] >= lmax[0] && lmax[1] >= lmax[2]) maxc = 1;
        else maxc = 2;

        sort(mems + 1, mems + n + 1, comp);
        int tot = 0;
        for (int i = 1; i <= n; i++)
        {
            if (mems[i].love[0][1] != maxc) ans += mems[i].love[0][0];
            else
            {
                if (tot < n / 2)
                {
                    ans += mems[i].love[0][0];
                    tot++;
                }
                else ans += mems[i].love[1][0];
            }
        }
        fout << ans << endl;
    }
    return 0;
}
