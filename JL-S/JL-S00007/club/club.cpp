// A
// expect pts = 100
// expect diff = idk, but i AC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// 哥你下次别出长得这么像dp的贪心好吗
// 孩子心脏不好使啊

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int, int> PII;
typedef long long LL;

int T;
int n;
int love[4][maxn];
int mx[maxn], mx2[maxn];
int cnt[4];
LL ans;
bool selmx[maxn];// i选的是不是最大的
int sel[maxn]; // i选的是哪个

void init()
{
    memset(selmx, 0, sizeof selmx);
    memset(cnt, 0, sizeof cnt);
    ans = 0;
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T --)
    {
        init();
        cin >> n;
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1; j <= 3 ; j ++)
                cin >> love[j][i];

        for(int i = 1 ; i <= n ; i ++)
        {
            mx[i] = max({love[1][i], love[2][i], love[3][i]});
            if(mx[i] == love[1][i]) mx2[i] = max(love[2][i], love[3][i]);
            if(mx[i] == love[2][i]) mx2[i] = max(love[1][i], love[3][i]);
            if(mx[i] == love[3][i]) mx2[i] = max(love[1][i], love[2][i]);
        }

        for(int i = 1 ; i <= n ; i ++)
        {
            int maxsel;// 当前哪个社团被选的最多
            if(cnt[1] > cnt[2] && cnt[1] > cnt[3]) maxsel = 1;
            if(cnt[2] > cnt[1] && cnt[2] > cnt[3]) maxsel = 2;
            if(cnt[3] > cnt[1] && cnt[3] > cnt[2]) maxsel = 3;

            int pos;
            for(int j = 1 ; j <= 3 ; j ++)
                if(mx[i] == love[j][i])
                    pos = j;
            selmx[i] = 1;
            sel[i] = pos;

            if(cnt[pos]+1 > n/2)
            {
                int minmx = 0x3f3f3f3f;// 已经选了最大的人的最小值
                int minmxpos = 0;// 他的位置
                for(int j = i ; j >= 1 ; j -- )
                    if(sel[j] == maxsel && minmx > (mx[j] - mx2[j]))//mx-mx2是牺牲当前的代价
                        minmx = mx[j] - mx2[j], minmxpos = j;

                if(minmxpos != i)
                {
                    sel[minmxpos] = 4;//debug
                    selmx[minmxpos] = 0;
                    ans -= mx[minmxpos];
                    ans += mx2[minmxpos];
                    ans += mx[i];
                }
                else
                {
                    sel[minmxpos] = 4;//debug
                    selmx[minmxpos] = 0;
                    ans += mx2[minmxpos];
                }
            }
            else
            {
                cnt[pos] ++;
                ans += mx[i];
                selmx[i] = 1;
                sel[i] = pos;
            }
            //cout << ans << endl;
        }
        cout << ans << endl;
        //cout << endl;
        /*
        for(int i = 1 ; i <= n ; i ++)
            cout << sel[i] << ' ';
        */
    }


}
