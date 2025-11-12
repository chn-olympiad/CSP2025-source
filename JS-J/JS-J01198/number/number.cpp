#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int k = s.size();
    int a[k + 1] = {0};
    int cnt = 0;
    for(int i = 0; i< k; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[cnt] = int(s[i] - '0');
            cnt++;
        }
    }
    sort(a, a + cnt);
    for(int i = cnt - 1; i >= 0; i--) cout << a[i];
}
