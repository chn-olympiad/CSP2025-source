#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int N = 1E5;
int a[N + 5][5];
int cnt[5];
int n;
struct ANS {
    vector <int> v;
    vector <int> number;
}ans[5];
void clean() {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 5; j++) {
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < 5; i++) {
        cnt[i] = 0;
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < ans[i].v.size(); j++) {
            ans[i].v[j] = 0;
            ans[i].number[j] = 0;
        }
    }
}
int cmp(int a[]) {
    int t[5];
    for(int i = 1; i <= 3; i++) {
        t[i] = a[i];
    }
    sort(t + 1, t + 4);
    return t[3];
}
void solve(int i) {
    int maxn = cmp(a[i]);
    int num;
    for(int j = 1; j <= n; j++) {
        if(a[i][j] == maxn) {
            num = j;
            a[i][j] = -1;
            break;
        }
    }
    if(cnt[num] < n / 2) {
        ans[num].v.push_back(maxn);
        ans[num].number.push_back(i);
        cnt[num]++;

    } else {
        int minn = ans[num].v[0];
        int x1;
        for(int j = 1; j < ans[num].v.size(); j++) {
            if(ans[num].v[j] < minn) {
                minn = ans[num].v[j];
                x1 = j;
            }
        }
        if(maxn > minn) {
            ans[num].v[x1] = maxn;
            int x2 = ans[num].number[x1];
            ans[num].number[x1] = i;
            solve(x2);
        } else {

        }
    }
    return;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        for(int i = 1; i <= n; i++) {
            solve(i);
        }
        int sum = 0;
        for(int i = 1; i <= 3; i++) {
            for(int j = 0; j < ans[i].v.size(); j++) {
                sum += ans[i].v[j];
            }
        }
        cout << sum << endl;
        clean();
    }
    return 0;
}
