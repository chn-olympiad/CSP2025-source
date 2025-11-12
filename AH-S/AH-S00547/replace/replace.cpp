#include <bits/stdc++.h>
using namespace std;
long n, p, to = 1, ans;
string L1[(int)(2e5+3)], L2[(int)(2e5+3)], l1, l2;
bool compare(string a, string b, int j)
{
    for (long i = 0; i < a.length(); i++)
        if (a[i] != b[i+j])
            return false;
    return true;
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> p;
    for (long i = 0; i < n; i++)
        cin >> L1[i] >> L2[i];
    long be = -1, fi;
    for (long i = 0; i < p; i++)
    {
        cin >> l1 >> l2;
        for (long i = 0; i < l1.length(); i++)
            if (l1[i] != l2[i])
            {
                if (be == -1)
                    be = i;
                else
                    fi = i;
            }
        for (long j = 0; j < l1.length(); j++)
            for (long k = 0; k < n; k++)
            {
                if (j <= be && j+L1[k].length() >= fi)
                    if (compare(L1[k], l1, j) && compare(L2[k], l2, j))
                        ans++;
            }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
