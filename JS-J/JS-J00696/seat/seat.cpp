#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int myscore, others, pm = 1;
    cin >> myscore;
    for (int i = 0; i < n * m - 1; i++) {
        cin >> others;
        if (others > myscore) pm++;
    }
    int mym= pm / n, myn = pm % n;
    if (pm % n != 0) mym++;
    if (mym % 2 == 0) myn = n - (myn - 1);
    if (pm % n == 0) {
        if (mym % 2 == 0) myn = 1;
        else myn = n;
    }
    cout << mym << " " << myn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
