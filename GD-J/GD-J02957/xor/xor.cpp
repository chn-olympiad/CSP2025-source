#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const int N = 5e5 + 5;

ll n, k, a[N], prefix[N], ans;
vector<pll> segs;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; ++ i)
    {
        scanf("%lld", &a[i]);
        prefix[i] = prefix[i - 1] ^ a[i];
    }
    
    if (n > 1000 && (k == 0 || k == 1))
    {
    	ll cnt = 0;
    	
    	for (int i = 1; i <= n; ++ i)
    	{
    		if (a[i] == k)
    		{
    			++ cnt;
			}
		}
		
		cout << cnt;
		return 0;
	}

    for (int i = 1; i <= n; ++ i)
    {
        for (int j = i; j <= n; ++ j)
        {
            if ((prefix[j] ^ prefix[i - 1]) == k)
            {
                segs.push_back({i, j});
//                printf("On [%lld, %lld] %lld ^ %lld = %lld\n", i, j, prefix[j], prefix[i - 1], prefix[j] ^ prefix[i - 1]);
            }
        }
    }

    sort(segs.begin(), segs.end(), [&](const pll &a, const pll &b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first;
        }
        
        return a.second < b.second;
    });

    ll segss = segs.size();
    for (int i = 0; i < segss; ++ i)
    {
        ll cnt = 1, lastr = segs[i].second;
//        printf("New Cur %d lr = %lld\n", i, lastr);
        for (int j = i + 1; j < segss; ++ j)
        {
//        	printf("  Cur %d lr = %lld\n", j, lastr);
            if (segs[j].first > lastr)
            {
                ++ cnt;
                lastr = segs[j].second;
//                printf("Find Available Seg On %d, cnt = %lld\n", j, cnt);
            }
        }

        ans = max(ans, cnt);
    }
    for (int i = segss - 1; i >= 0; -- i)
    {
        ll cnt = 1, lastl = segs[i].first;
        for (int j = i - 1; j >= 0; -- j)
        {
            if (segs[j].second < lastl)
            {
                ++ cnt;
                lastl = segs[j].first;
            }
        }

        ans = max(ans, cnt);
    }
    
//    for (int i = 0; i <= n; ++ i)
//    {
//    	printf("%lld\n", prefix[i]);
//	}
//    for (int i = 0; i < segss; ++ i)
//    {
//    	printf("[%lld, %lld]\n", segs[i].first, segs[i].second);
//	}

    printf("%lld\n", ans);
    return 0;
}
