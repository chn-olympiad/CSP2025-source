#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n;
int a[N][3];
int c[N];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d", &n);
        int cnt[3] = {0};
        for (int i = 1; i <= n; i ++ ) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);  
        for (int i = 1; i <= n; i ++ )
        {
            if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) cnt[0] ++, c[i] = 0;
            else if (a[i][1] >= a[i][2]) cnt[1] ++, c[i] = 1;
            else cnt[2] ++, c[i] = 2;
        }
        int maxv = 0;
        if (cnt[1] > cnt[maxv]) maxv = 1;
        if (cnt[2] > cnt[maxv]) maxv = 2;
        //cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << endl;
        vector<int> nums;
        for (int i = 1; i <= n; i ++ )
            if (c[i] == maxv)
            {
                int val = 2e9;
                for (int j = 0; j < 3; j ++ )
                    if (j != maxv) val = min(val, a[i][maxv] - a[i][j]);
                nums.push_back(val);
            }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i <= n; i ++ ) ans += a[i][c[i]];//cout << ans << ' ';
        for (int i = 0; i < cnt[maxv] - n / 2; i ++ )
            ans -= nums[i];
        printf("%d\n", ans);
    }

    return 0;
}