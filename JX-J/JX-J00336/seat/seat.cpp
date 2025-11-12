//9:40 easy!
#include <bits/stdc++.h>
#define buff ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const int MAXN = 10 + 5;
const int MAXM = 10 + 5;

int n, m;
int c, r;
int cnt = 1;
bool flag = true;
int num[MAXN * MAXM];
int mp[MAXN][MAXM];

bool cmp(int x, int y)
{
    return x > y;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    buff;

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> num[i];
    }
    int ans = num[1];
    sort(num + 1, num + 1 + (n * m), cmp);

    /*
    cout << "-----" << endl;
    for (int i = 1; i <= n * m; i++)
    {
        cout << num[i] << ' ';
    }
    cout << endl << "-----" << endl;
    */

    for (int j = 1; j <= m; j++)
    {
        if (flag)
        {
            for (int i = 1; i <= n; i++)
            {
                mp[i][j] = num[cnt++];
            }
            flag = false;
        }
        else
        {
            for (int i = n; i >= 1; i--)
            {
                mp[i][j] = num[cnt++];
            }
            flag = true;
        }
    }
    /*
    cout << "-----" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "-----" << endl;
    */

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (mp[i][j] == ans)
            {
                //cout << mp[i][j] << ' ' << ans << endl << "-----" << endl;
                c = j;
                r = i;
            }
        }
    }

    cout << c << ' ' << r;
    return 0;
}
/*
10 10
46 2 5 6 7 8 9 10 11 14 15 16 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 47 48 49 50 51 52 53 54 55 56 57 58 59 60 62 61 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 79 80 81 82 83 84 85 86 87 88 89 90 92 93 94 95 96 97 98 99 45 4 17 91 78 100 13 3 1 12

6 6
*/
//10:28 very easy!
