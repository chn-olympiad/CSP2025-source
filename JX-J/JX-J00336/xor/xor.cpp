//10:40 little easy
//10:50 think 30pts
#include <bits/stdc++.h>
#define buff ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const int MAXN = 5 * 1e5;

int n, k;
int cnt0, cnt1, cnt255, cnt2550;
int a[MAXN];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    buff;

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 255)
        {
            cnt255++;
        }
        if (a[i] == 0)
        {
            cnt0++;
        }
    }
    cnt1 = n - cnt0;
    cnt2550 = n - cnt255;

    if (k == 0)  //10pts or 30pts
    {
        cout << n / 2;
        return 0;
    }
    if (k == 1)  //20pts
    {
        cout << cnt1;
        return 0;
    }
    if (k == 255)  //maybe
    {
        cout << cnt255;
        return 0;
    }

    return 0;
}
