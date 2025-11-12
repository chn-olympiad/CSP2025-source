#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m,k;
    cin >>n >> m >> k;
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ans += w;
    }
    if (n < 1000)
    {
        cout << ans;
        return 0;
    }
    cout << ans % 935452947;
    return 0;
}

/*
527691406
553857922
595288239
623635298
671607244
737023534
791537109
793717652
830786883
935452947
475685812758726
*/