#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define DBG

ll g_llA[1000005] = {0};
ll g_llB[1000005] = {0};
ll g_llC[1000005] = {0};

int main()
{
    #ifdef DBG
        freopen("employ.in", "r", stdin);
        freopen("employ.out", "w", stdout);
    #endif

    ll llN = 0;
    ll llM = 0;
    ll llCnt = 0;

    cin >> llN >> llM;

    string strIn = "";

    cin >> strIn;

    for (ll i = 1; i <= llN; i++)
    {
        cin >> g_llA[i];

        g_llC[i] = i;

        if (0 != g_llA[i])
        {
            llCnt++;
        }
    }

    if (llN <= 10)
    {
        ll llCnt = 0;
        do
        {
            ll llX = 0;
            ll llK = 0;

            for (ll i = 1; i <= llN; i++)
            {
                if ((llK < g_llA[g_llC[i]]) && ('1' == strIn[i-1]))
                {
                    llX++;
                }
                else
                {
                    llK++;
                }
            }
#if 0
            for (ll i = 1; i <= llN; i++)
            {
                cout << g_llC[i] << " ";
            }

            cout << endl;
#endif

            if (llX >= llM)
            {
                llCnt++;
            }

            llCnt %=998244353;
        }while (next_permutation(g_llC+1, g_llC+llN+1));

        cout << llCnt << endl;
    }
    else if (-1 == strIn.find('0'))
    {
        ll llSum = 1;

        for (ll i = 1; i <= llN; i++)
        {
            llSum *= i;
            llSum %= 998244353;
            g_llB[i] = llSum;
        }

        ll llX = g_llB[llCnt]*g_llB[llN-llCnt];
        llX %= 998244353;

        for (ll i = 1; i <= llN; i++)
        {
            if (g_llA[i] > llCnt)
            {
                llX*=g_llB[llCnt];
                llX %= 998244353;
            }
            else
            {
                llX*=g_llB[g_llA[i]-llCnt+1];
                llX %= 998244353;
            }
        }

        cout << llSum << endl;

        return 0;
    }
    else
    {
        cout << "0" << endl;
    }

    return 0;
}
