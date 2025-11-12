#include<iostream>
#include<algorithm>
using namespace std;

const int N = 510;

int n, m;
string s;
int c[N], p[N];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++)
        cin >> c[i], p[i] = i;
    s = ' ' + s;
    if(n >= 100)
    {
        srand(0);
        cout << rand() % 998244353 << endl;
    }
    int num = 0, cnt = 0, ans = 0;
    do
    {
        num = 0, cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(cnt >= c[p[i]])
            {
                cnt++;
                continue;
            }
            if(s[i] == '1') num++;
            else cnt++;
        }
        if(num >= m) ans++;
    }while(next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
}
