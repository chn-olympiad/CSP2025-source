#include <bits/stdc++.h>

//RP++

using namespace std;

const int MAXN = 5e5 + 5;


int n, k;

int a[MAXN];

int pr[MAXN];

int cnt[MAXN];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pr[i] = pr[i - 1] ^ a[i];
        
    }


    // int ans1 = a[2];
    // for(int i = 3; i <= 4; i++)
    // {
    //     ans1 = ans1 ^ a[i];
    // }
    // int ans2 = pr[1] ^ pr[4];
    // cout << ans1 << "\n" << ans2;


    /*
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            
            if((pr[i - 1] ^ pr[j]) == k)
            {
                cnt++;
                //cout << pr[i - 1] << "^" << pr[j] << "=" << (pr[i - 1] ^ pr[j]) << "\n"; 
                //cout << i << " " << j << "\n";
            }
        }
    }
    */
    for(int a = 1; a <= n; a++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j++)
            {
                if((pr[i - 1] ^ pr[j]) == k)
                {
                    cnt[a]++;
                    i = j + 1;
                }
            }
        }
    }

    //O(n^3) ???
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, cnt[i]);
    }
    cout << ans;
    return 0;
}
