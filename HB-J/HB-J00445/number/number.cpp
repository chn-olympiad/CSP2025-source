#include <bits/stdc++.h>

using namespace std;
int a[1000005];
char tmp;
string x, ans;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> x;
    int j = 0;
    for(int i = 0; i < x.length(); i++)
    {
        if(x[i] >= 48 && x[i] <= 57)
        {
            a[j] = x[i] - '0';
            j++;
        }
    }
    sort(a, a + j + 1, cmp);
    for(int i = 0; i < j; i++) ans += a[i] + '0';
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
