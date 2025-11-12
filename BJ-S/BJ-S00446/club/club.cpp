#include<bits/stdc++.h>
using namespace std;
int a[100010][4], b[4][100010], cnt[4], bu, n;
bool cmp(int x, int y)
{
    int t1 = a[x][bu] - max(a[x][(bu + 1) % 3], a[x][(bu + 2) % 3]);
    int t2 = a[y][bu] - max(a[y][(bu + 1) % 3], a[y][(bu + 2) % 3]);
    return t1 > t2;
}
void suan()
{
    
    sort(b[bu] + 1, b[bu] + cnt[bu] + 1, cmp);
    //cout << b[bu][1] << " " << b[bu][2] << endl;
    while(cnt[bu] > n / 2)
    {
        int x = b[bu][cnt[bu]];
        if(a[x][(bu + 1) % 3] >= a[x][(bu + 2) % 3])
        {
            b[(bu + 1) % 3][++cnt[(bu + 1) % 3]] = b[bu][cnt[bu]--];
        }
        else
        {
            b[(bu + 2) % 3][++cnt[(bu + 2) % 3]] = b[bu][cnt[bu]--];
        }
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
            {
                b[1][++cnt[1]] = i;
            }
            if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
            {
                b[2][++cnt[2]] = i;
            }
            if(a[i][3] >= a[i][2] && a[i][3] >= a[i][1])
            {
                b[3][++cnt[3]] = i;
            }
        }
        for(int i = 1; i <= 3; i++)
        {
            if(cnt[i] > n / 2)
            {
                bu = i;
                suan();
            }
        }
        
        
        long long ans = 0;
        for(int i = 1; i <= 3; i++)
        {
            for(int j = 1; j <= cnt[i]; j++)
            {
                ans += a[b[i][j]][i];
            }
        }
        cout << ans << endl;
        cnt[1] = cnt[2] = cnt[3] = 0;
        memset(a, 0, sizeof(a));
        bu = 0;
    }
    return 0;
}