#include<bits/stdc++.h>
using namespace std;

unsigned short t, n, a[100005][8];
int ans;

void v(unsigned short mx, short my, int fcnt, bool fflag[], unsigned short fmmax[])
{
    if(mx == n)
    {
        if((fcnt + a[mx][my]) > ans)
        {
            ans = fcnt + a[mx][my];
        }
        return;
    }
    unsigned short mmax[8];
    bool flag[8];
    flag[1] = fflag[1];
    flag[2] = fflag[2];
    flag[3] = fflag[3];
    mmax[1] = fmmax[1];
    mmax[2] = fmmax[2];
    mmax[3] = fmmax[3];
    mmax[my]++;
    if((!flag[my]) and (mmax[my] == (n / 2)))
    {
        flag[my] = 1;
    }
    if(!flag[1])
    {
        v(mx + 1, 1, fcnt + a[mx][my], flag, mmax);
    }
    if(!flag[2])
    {
        v(mx + 1, 2, fcnt + a[mx][my], flag, mmax);
    }
    if(!flag[3])
    {
        v(mx + 1, 3, fcnt + a[mx][my], flag, mmax);
    }
}

void msolve()
{
    unsigned short mmax[8];
    bool flag[8];
    mmax[1] = mmax[2] = mmax[3] = 0;
    flag[1] = flag[2] = flag[3] = 0;
    v(1, 1, 0, flag, mmax);
    v(1, 2, 0, flag, mmax);
    v(1, 3, 0, flag, mmax);
    cout << ans << '\n';
    ans = 0;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        msolve();
    }
    return 0;
}
