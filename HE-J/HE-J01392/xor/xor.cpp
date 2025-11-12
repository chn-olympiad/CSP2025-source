//wen la
#include <bits/stdc++.h>
using namespace std;
int n, k, a[501000], s[500100];
map<int, vector<int>> cnt;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int sum = 0, ans = 0;
    int p = 0;
    cnt[0].push_back(0);
    for(int i = 1; i <= n; i++){
        sum ^= a[i];
        s[i] = sum;
        // sum ^ ? = k
        //sum ^ k = ?
        if(cnt.count(sum ^ k))
            if(!cnt[sum ^ k].empty()){
                ans += 1;
                for(int j = p; j < i; j++)
                    cnt[s[j]].pop_back();
                p = i;
            }
        cnt[sum].push_back(i);
    }
    printf("%d\n", ans);
    return 0;
}
