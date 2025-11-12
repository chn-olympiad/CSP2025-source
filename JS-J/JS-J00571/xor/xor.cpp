#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, k, a[N];

bool special_a;

bool special_b;
bool spb_used[N];

struct Range{
    int st;
    int ed;
} range[1000005];
int bf_cnt;
bool cmp(Range x, Range y){
    return x.ed < y.ed;
}

void spa(){
    cout << n / 2;
}
void spb(){
    if(k == 1){
        int cnt1 = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] == 1) ++cnt1;
        }
        cout << cnt1;
    }else{
        int cnt0 = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] == 0) ++cnt0;
            else if(a[i] == 1 && a[i-1] == 1 && !spb_used[i-1]){
                spb_used[i-1] = spb_used[i] = 1;
                ++cnt0;
            }
        }
        cout << cnt0;
    }
}
void Brute_force(){
    int cnt = 0;
    // Get the ranges.
    for(int i = 1; i <= n; ++i){
        int tmp = 0;
        for(int j = i; j <= n; ++j){
            tmp ^= a[j];
            if(tmp == k){
                range[++bf_cnt].st = i;
                range[bf_cnt].ed = j;
            }
        }
    }
    // Greedy Algorithm.
    sort(range + 1, range + 1 + bf_cnt, cmp);
    int ans = 0, lst_ed = 0;
    for(int i = 1; i <= bf_cnt; ++i){
        if(range[i].st > lst_ed){
            lst_ed = range[i].ed;
            ++ans;
        }
    }
    cout << ans;
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    special_a = special_b = 1;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(special_a && a[i] != 1) special_a = 0;
        if(special_b && a[i] != 0 && a[i] != 1) special_b = 0;
    }
    // Divide into Sub tasks.
    // Damn, is this crazy NOI question for human beings?
    if(special_a) spa();
    else if(special_b) spb();
    else if(n <= 1000) Brute_force();
    else Brute_force();
    return 0;
}
