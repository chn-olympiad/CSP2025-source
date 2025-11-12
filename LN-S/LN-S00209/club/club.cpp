#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int z1[N], z2[N], z3[N];
int cz1, cz2, cz3;
long long al1, al2, al3;
struct peo
{
    int d1, d2, d3;
} a[N];
bool cmp1(int x, int y)
{
    return a[x].d1-max(a[x].d2,a[x].d3) < a[y].d1-max(a[y].d2,a[y].d3);
}
bool cmp2(int x, int y)
{
    return a[x].d2-max(a[x].d1,a[x].d3) < a[y].d2-max(a[y].d1,a[y].d3);
}
bool cmp3(int x, int y)
{
    return a[x].d3-max(a[x].d2,a[x].d1) < a[y].d3-max(a[y].d2,a[y].d1);
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cz1 = 0, cz2 = 0, cz3 = 0;
        al1 = 0, al2 = 0, al3 = 0;

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
        }
        int a1, a2, a3;
        for (int i = 1; i <= n; i++)
        {
            a1 = a[i].d1, a2 = a[i].d2, a3 = a[i].d3;
            if (a1 >= a2 && a1 >= a3)
            {
                z1[++cz1] = i;
                al1 += a1;
            }
            else if (a2 >= a1 && a2 >= a3)
            {
                z2[++cz2] = i;
                al2 += a2;
            }
            else
            {
                z3[++cz3] = i;
                al3 += a3;
            }
        }
        if (cz1 > n / 2)
        {
            //cout << 1 << " ";
            stable_sort(z1 + 1, z1 + 1 + cz1, cmp1);
            for (int i = 1; i <=  cz1-n/2; i++)
            {
                //cout << "-"
                    // << " ";
                al1 -= a[z1[i]].d1;
                if (a[z1[i]].d2 > a[z1[i]].d3)
                    al2 += a[z1[i]].d2;
                else
                    al3 += a[z1[i]].d3;
            }
        }
        else if (cz2 > n / 2)
        {
            //cout << 2 << " ";
            stable_sort(z2 + 1, z2 + 1 + cz2, cmp2);
            for (int i = 1; i <=  cz2-n/2; i++)
            {
                //cout << "-"
                 //    << " ";
                al2 -= a[z2[i]].d2;
                if (a[z2[i]].d1 > a[z2[i]].d3)
                    al1 += a[z2[i]].d1;
                else
                    al3 += a[z2[i]].d3;
            }
        }
        else if (cz3 > n / 2)
        {
            //cout << 3 << " ";
            stable_sort(z3 + 1, z3 + 1 + cz3, cmp3);
            for (int i = 1; i <=  cz3-n/2; i++)
            {
                //cout << "-"
                 //    << " ";
                al3 -= a[z3[i]].d3;
                if (a[z3[i]].d1 > a[z3[i]].d2)
                    al1 += a[z3[i]].d1;
                else
                    al2 += a[z3[i]].d2;
            }
        }
        //cout << al1 << " " << al2 << " " << al3 << " ";
        cout << al1 + al2 + al3 << "\n";
    }

    return 0;
}
