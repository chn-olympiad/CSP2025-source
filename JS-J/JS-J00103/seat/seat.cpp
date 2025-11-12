#include <bits/stdc++.h>
using namespace std;
int n, m;
int sc[110];
int pm;
void cpm()
{
    pm = 1;
    for (int i = 2; i <= n * m; i++)
    {
        if (sc[i] > sc[1]) pm++;
    }
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> sc[i];
    }
    cpm();
    int lie = (pm - 1) / n + 1;
    int hang;
    if (lie % 2 == 0)
    {
        hang = pm / n;
        if (hang == 0) hang = n;
        hang = n + 1 - hang;
    }
    else
    {
        hang = pm % n;
        if (hang == 0) hang = n;
    }
    cout << lie << ' ' << hang;
    return 0;
}
