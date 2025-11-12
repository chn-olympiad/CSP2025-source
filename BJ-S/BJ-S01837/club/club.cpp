#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int T;
int n;
int v[N][10];
int maxn[N];
priority_queue<int, vector<int>, greater<int> > heap;
long long int ans;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T -- )
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) cin >> v[i][0] >> v[i][1] >> v[i][2];
        int cnta = 0, cntb = 0, cntc = 0;
        ans = 0;
        for(int i = 1; i <= n; i ++) 
        {
            maxn[i] = max(v[i][0], max(v[i][1], v[i][2]));
            if(maxn[i] == v[i][0]) cnta ++ ;
            if(maxn[i] == v[i][1]) cntb ++ ;
            if(maxn[i] == v[i][2]) cntc ++ ;
            ans += maxn[i];
        }
        int M = -1;
        int m1 = -1, m2 = -1;
        int ma = -1;
        if(cnta > (n / 2)) M = cnta, m1 = 1, m2 = 2, ma = 0;
        if(cntb > (n / 2)) M = cntb, m1 = 0, m2 = 2, ma = 1;
        if(cntc > (n / 2)) M = cntc, m1 = 0, m2 = 1, ma = 2;
        if(M == -1) cout << ans << endl;
        else{
            for(int i = 1; i <= n; i ++) 
                if(maxn[i] == v[i][ma])
                    heap.push(maxn[i] - max(v[i][m1], v[i][m2]));
            int o = M - (n / 2);
            while(o -- )
            {
                int t = heap.top();
                heap.pop();
                ans -= t;
            }
            while(!heap.empty()) heap.pop();
            cout << ans << endl;
        }
    }
    return 0;
}