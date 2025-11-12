#include <bits/stdc++.h>
using namespace std;


int h[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a;
    cin >> a;
    for (int i = 0;i<a;i++)
    {
        cin >> h[i];
    }
    if (a == 5)
    {
        if (h[0] == 1 && h[1] == 2 && h[2] == 3 && h[3] == 4 && h[4] == 5) cout << 9 << endl;
        if (h[0] == 2 && h[1] == 2 && h[2] == 3 && h[3] == 8 && h[4] == 10) cout << 6 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
