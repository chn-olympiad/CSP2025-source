#include<bits/stdc++.h>
using namespace std;
int x[100005][5],mp[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int z = 0;z <= t;z++)
    {
        int n,ans = 0,ac = 0,bc = 0,cc = 0;
        cin >> n;
        int mn = n / 2;
        for(int i = 1;i <= n;i++)
        {
            cin >> x[i][1] >> x[i][2] >> x[i][3];
            int maxn = max({x[i][1],x[i][2],x[i][3]});
            if(maxn == x[i][1])
            {
                ac++;
                mp[i] = 1;
            }
            else if(maxn == x[i][2])
            {
                bc++;
                mp[i] = 2;
            }
            else if(maxn == x[i][3])
            {
                cc++;
                mp[i] = 3;
            }
        }
        while(ac>mn||bc>mn||cc>mn)
        {
            int ma = 20005,mb = 20005,mc = 20005,sa = 0,sb = 0,sc = 0;
            for(int i = 1;i <= n;i++)
            {
                if(mp[i] == 1 && x[i][1] - x[i][2] < ma)
                {
                    ma = x[i][1] - x[i][2];
                    sa = i;
                }
                else if(mp[i] == 2 && x[i][2] - x[i][3] < mb)
                {
                    mb = x[i][2] - x[i][3];
                    sb = i;
                }
                else if(mp[i] == 3 && x[i][3] - x[i][1] < mc)
                {
                    mc = x[i][3] - x[i][1];
                    sc = i;
                }
            }
            if(ac > mn)
            {
                ac--;
                if(x[sa][mp[sa]+1] < x[sa][mp[sa]+2] && cc+1<=mn)
                {
                    mp[sa]+=2;
                    cc++;
                }
                else
                {
                    mp[sa]++;
                    bc++;
                }

            }
            else if(bc > mn)
            {
                bc--;
                if(x[sb][mp[sb]+1] < x[sb][mp[sb]-1]&&ac+1<=mn)
                {
                    mp[sb]--;
                    ac++;
                }
                else
                {
                    mp[sb]++;
                    cc++;
                }
            }
            else if(cc > mn)
            {
                cc--;
                if(x[sc][mp[sc]-2] < x[sc][mp[sc]-1]&&bc+1<=mn)
                {
                    mp[sc]--;
                    bc++;
                }
                else
                {
                    mp[sc]-=2;
                    ac++;
                }
            }
        }
        for(int i = 1;i <= n;i++)
        {
            ans += x[i][mp[i]];
        }
        cout << ans << "\n";
    }
    return 0;
}
