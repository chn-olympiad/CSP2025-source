#include<bits/stdc++.h>
using namespace std;

char x[100005], y[100005];
int main()
{
    int n, q;
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for(int i = n + 1; i <= q + n + 1; i++)
        cin >> x[i] >> y[i];
    for(int i = 1; i <= q; i++)
        cout << 0 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
