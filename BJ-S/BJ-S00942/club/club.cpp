#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN][4];
int a1[MAXN],a2[MAXN],a3[MAXN],b[MAXN];

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n,cnt1 = 0,cnt2 = 0,cnt3 = 0;
        long long ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
            {
                a1[++cnt1] = i;
                ans += a[i][1];
            }
            if(a[i][2] > a[i][1] && a[i][2] >= a[i][3])
            {
                ans += a[i][2];
                a2[++cnt2] = i;
            }
            if(a[i][3] > a[i][1] && a[i][3] > a[i][2])
            {
                ans += a[i][3];
                a3[++cnt3] = i;
            }
        }
        if(cnt1 > n/2)
        {
            for(int i = 1;i <= cnt1;i++) b[i] = min(a[a1[i]][1]-a[a1[i]][2],a[a1[i]][1]-a[a1[i]][3]);
            sort(b+1,b+cnt1+1);
            for(int i = 1;i <= cnt1-n/2;i++) ans -= b[i];
        }
        if(cnt2 > n/2)
        {
            for(int i = 1;i <= cnt2;i++) b[i] = min(a[a2[i]][2]-a[a2[i]][1],a[a2[i]][2]-a[a2[i]][3]);
            sort(b+1,b+cnt2+1);
            for(int i = 1;i <= cnt2-n/2;i++) ans -= b[i];
        }
        if(cnt3 > n/2)
        {
            for(int i = 1;i <= cnt3;i++) b[i] = min(a[a3[i]][3]-a[a3[i]][1],a[a3[i]][3]-a[a3[i]][2]);
            sort(b+1,b+cnt3+1);
            for(int i = 1;i <= cnt3-n/2;i++) ans -= b[i];
        }
        cout << ans << endl;
    }
    return 0;
}
