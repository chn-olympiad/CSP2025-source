#include <bits/stdc++.h>
#define in long long
using namespace std;

const int maxn = 205;
in n, ma = -1, cnt[5], e = 0;

struct node {
    in s1, s2, s3;
}a[maxn];

bool cmp(node x, node y){
    if(x.s2 <= x.s3 && y.s2 <= y.s3)
        return x.s3 > y.s3;
    else
        return x.s2 > y.s2;
}

void dfs(in x, in temp) {
    e++;
    if(x > n || e >= 28e6) {
        ma = max(ma, temp);
        return ;
    }
    int o = max(a[x].s1, max(a[x].s2, a[x].s3));
    if(a[x].s3 == o)
    {
        if(cnt[3] < n/2) {
            cnt[3]++;
            dfs(x+1, temp+a[x].s3);
            cnt[3]--;
        }
        if(cnt[2] < n/2) {
            cnt[2]++;
            dfs(x+1, temp+a[x].s2);
            cnt[2]--;
        }
        if(cnt[1] < n/2) {
            cnt[1]++;
            dfs(x+1, temp+a[x].s1);
            cnt[1]--;
    }
    }else if(a[x].s2 == o) {
        if(cnt[2] < n/2) {
            cnt[2]++;
            dfs(x+1, temp+a[x].s2);
            cnt[2]--;
        }
        if(cnt[1] < n/2) {
            cnt[1]++;
            dfs(x+1, temp+a[x].s1);
            cnt[1]--;
        }
        if(cnt[3] < n/2) {
            cnt[3]++;
            dfs(x+1, temp+a[x].s3);
            cnt[3]--;
        }
    }
    if(cnt[1] < n/2) {
        cnt[1]++;
        dfs(x+1, temp+a[x].s1);
        cnt[1]--;
    }
    if(cnt[3] < n/2) {
        cnt[3]++;
        dfs(x+1, temp+a[x].s3);
        cnt[3]--;
    }
    if(cnt[2] < n/2) {
        cnt[2]++;
        dfs(x+1, temp+a[x].s2);
        cnt[2]--;
    }
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        memset(a,0,sizeof(a));
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
        }
        sort(a+1, a+n+1, cmp);
        ma = -1, e = 0;
        dfs(1, 0);
        cout << ma << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
