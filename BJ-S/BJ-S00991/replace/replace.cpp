#include<bits/stdc++.h>
using namespace std;
struct s
{
    string xy, bq;
}a[100005];
map<string, int> mp;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i].xy >> a[i].bq, mp[a[i].xy]++;
    while(q--)
    {
        string zzr, zzx;
        cin >> zzr >> zzx;
        if(mp[zzr] == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i].xy == zzr)
            {
                bool f = 1;
                for(int j = 0; j < zzx.size(); j++)
                {
                    if(a[i].xy[j] != zzx[j] && a[i].bq[j] != zzx[j])
                    {
                        f = 0;
                        break;
                    }
                }
                if(!f) continue;
                f = 1;
                int left = 0, right = 0;
                for(int j = 0; j < zzx.size(); j++)
                {
                    if(a[i].xy[j] == zzx[j] && f) left++;
                    else if(a[i].xy[j] == zzx[j] && !f) right++;
                    else f = 0;
                }
                //cout << left << ' ' << right << endl;
                res += (left+1)*(right+1);
            }
        }
        cout << res << endl;
    }
    return 0;
}
