#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define DBG

ll g_llA[100005] = {0};
ll g_llB[100005] = {0};
ll g_llC[100005] = {0};
ll g_llMax = 0;

void dfs(ll llStep, ll llX, ll llY, ll llZ, ll llN, ll llSum)
{
    if ((llX > (llN/2)) || (llY > (llN/2)) || (llZ > (llN/2)))
    {
        return;
    }

    if (llStep == (llN+1))
    {
        g_llMax = max(g_llMax, llSum);
        return;
    }

    dfs(llStep+1, llX+1, llY, llZ, llN, llSum + g_llA[llStep]);
    dfs(llStep+1, llX, llY+1, llZ, llN, llSum + g_llB[llStep]);
    dfs(llStep+1, llX, llY, llZ+1, llN, llSum + g_llC[llStep]);
}

void solve()
{
    g_llMax = 0;
    ll llN = 0;
    bool bFlag1 = false;
    bool bFlag2 = false;

    cin >> llN;

    for (ll i = 1; i <= llN; i++)
    {
        cin >> g_llA[i] >> g_llB[i] >> g_llC[i];

        if ((0 != g_llB[i]) || (0 != g_llC[i]))
        {
            bFlag1 = true;
        }

        if (0 != g_llC[i])
        {
            bFlag2 = true;
        }
    }

    if (!bFlag1 || !bFlag2)
    {
        sort(g_llA+1, g_llA+llN+1);
        ll llSum = 0;

        for (ll i = llN; i > llN/2; i--)
        {
            llSum += g_llA[i];
        }

        cout << llSum << endl;
        return ;
    }

    dfs(1, 0, 0, 0, llN, 0);

    cout << g_llMax << endl;
}

int main()
{
    #ifdef DBG
        freopen("club.in", "r", stdin);
        freopen("club.out", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll llT = 0;

    cin >> llT;

    for (ll i = 1; i <= llT; i++)
    {
        solve();
    }

    return 0;
}
