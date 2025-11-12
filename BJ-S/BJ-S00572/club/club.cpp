#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
struct Node{
    int x, y, z;
} a[N];

bool cmp1(int i, int j){
    return min(a[i].x-a[i].y, a[i].x-a[i].z) < min(a[j].x-a[j].y, a[j].x-a[j].z);
}

bool cmp2(int i, int j){
    return min(a[i].y-a[i].x, a[i].y-a[i].z) < min(a[j].y-a[j].x, a[j].y-a[j].z);
}

bool cmp3(int i, int j){
    return min(a[i].z-a[i].x, a[i].z-a[i].y) < min(a[j].z-a[j].x, a[j].z-a[j].y);
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        vector<int> d1, d2, d3;
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a[i].x >> a[i].y >> a[i].z;
        }
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
        for(int i = 0;i < n;i++){
            if(a[i].x >= a[i].y && a[i].x >=a[i].z){
                cnt1++, ans += a[i].x;
                d1.push_back(i);
            } else if(a[i].y >= a[i].x && a[i].y >=a[i].z){
                cnt2++, ans += a[i].y;
                d2.push_back(i);
            } else{
                cnt3++, ans += a[i].z;
                d3.push_back(i);
            }
        }
        if(cnt1 <= n/2 && cnt2 <= n/2 && cnt3 <= n/2) cout << ans << '\n';
        else {
            if(cnt1 > n/2){
                sort(d1.begin(), d1.end(), cmp1);
                for(int i = 0;i < cnt1-(n/2);i++){
                    if(a[d1[i]].x-a[d1[i]].y <= a[d1[i]].x-a[d1[i]].z){
                        cnt2++, ans -= a[d1[i]].x, ans += a[d1[i]]
                        .y;
                        d2.push_back(i);
                    } else {
                        cnt3++, ans -= a[d1[i]].x, ans += a[d1[i]].z;
                        d3.push_back(i);
                    }
                }
            }

            if(cnt2 > n/2){
                sort(d2.begin(), d2.end(), cmp2);
                for(int i = 0;i < cnt2-(n/2);i++){
                    if(a[d2[i]].y-a[d2[i]].x <= a[d2[i]].y-a[d2[i]].z && cnt1 < n/2){
                        ans -= a[d2[i]].y, ans += a[d2[i]].x;
                    } else {
                        cnt3++, ans -= a[d2[i]].y, ans += a[d2[i]].z;
                        d3.push_back(i);
                    }
                }
            }

            if(cnt3 > n/2) {
                sort(d3.begin(), d3.end(), cmp3);
                for(int i = 0;i < cnt3-(n/2);i++){
                    if(a[d3[i]].z-a[d3[i]].x <= a[d3[i]].z-a[d3[i]].y && cnt1 < n/2){
                        ans -= a[d3[i]].z, ans += a[d3[i]].x;
                    } else {
                        ans -= a[d3[i]].z, ans += a[d3[i]].y;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
