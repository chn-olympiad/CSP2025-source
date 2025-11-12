#include<bits/stdc++.h>
using namespace std;
namespace Aurora{ void Main(); }
int main(){ return Aurora::Main(), 0; }
namespace Aurora{
    #define ll long long
    const int N = 1e5 + 5;
    int n;
    struct Pr{ int val, id; };
    struct Node{ 
        Pr c[5]; 
    }a[N];
    vector<int>res[10];
    int cnt[10];
    bool cmp(Pr A, Pr B){ return A.val > B.val; }
    void Reset(){
        for(int i = 1; i <= 3; i++) res[i].clear(), cnt[i] = 0;
    }
    void Solve(){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i].c[1].val, &a[i].c[2].val, &a[i].c[3].val);
            a[i].c[1].id = 1; a[i].c[2].id = 2; a[i].c[3].id = 3;
            sort(a[i].c + 1, a[i].c + 3 + 1, cmp);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            cnt[a[i].c[1].id]++; ans += a[i].c[1].val;
            res[a[i].c[1].id].push_back(a[i].c[1].val - a[i].c[2].val);
        }
        for(int i = 1; i <= 3; i++){
            if(cnt[i] > n / 2){
                sort(res[i].begin(), res[i].end());
                int tim = cnt[i] - n / 2;
                for(int j = 0; j < tim; j++) ans -= res[i][j];
            }
        }
        printf("%d\n", ans);
    }
    void Main(){
        freopen("club.in", "r", stdin);
        freopen("club.out", "w", stdout);
        int T; scanf("%d", &T);
        while(T--) Reset(), Solve();
    }
}