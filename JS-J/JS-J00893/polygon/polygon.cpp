#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5000;
int length[MAXN+3];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> length[i];
    for(int i = 7 ; i <= (1 << n)-1 ; i++)
    {
        int max_num = 0 , total = 0 , select_cnt = 0;
        for(int j = 0 ; j <= n ; j++)
        {
            if (i & (1 << j))
            {
                select_cnt++;
                max_num = max(max_num , length[j]);
                total += length[j];
            }
        }
        if (select_cnt < 3) continue;
        if (total > max_num * 2)
        {
            ans++;
        }
    }
    printf("%d",ans);
}
