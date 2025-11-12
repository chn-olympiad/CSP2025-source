#include<bits/stdc++.h>
#define int long long

using namespace std;

const int Maxn = 1e5 + 5;

int n, ans;
int a[Maxn][4];

vector<int> pos[4];

bool cmp1(int x, int y){
    return (a[x][1] - max(a[x][2], a[x][3])) > (a[y][1] - max(a[y][2], a[y][3]));
}

bool cmp2(int x, int y){
    return (a[x][2] - max(a[x][1], a[x][3])) > (a[y][2] - max(a[y][1], a[y][3]));
}

bool cmp3(int x, int y){
    return (a[x][3] - max(a[x][2], a[x][1])) > (a[y][3] - max(a[y][2], a[y][1]));
}

void init(){
    for(int i = 1; i <= 3; i ++) pos[i].clear();
    ans = 0;
    memset(a, 0, sizeof(a));
}

void work(){
    //ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        int mx = max(a[i][1] , max(a[i][2], a[i][3]));
        if(a[i][1] == mx) pos[1].push_back(i);
        else if(a[i][2] == mx) pos[2].push_back(i);
        else if(a[i][3] == mx) pos[3].push_back(i);
        ans += mx;
    }

    int cur = 0;
    for(int i = 1; i <= 3; i ++)
        if(pos[i].size() > n / 2){
            cur = i;
            break;
        }

    if(cur == 1){
        sort(pos[1].begin(), pos[1].end(), cmp1);
        while(pos[1].size() > n / 2){
            int ps = pos[1][pos[1].size() - 1];
            ans -= (a[ps][1] - max(a[ps][2], a[ps][3]));
            pos[1].pop_back();
        }
    }

    if(cur == 2){
        sort(pos[2].begin(), pos[2].end(), cmp2);
        while(pos[2].size() > n / 2){
            int ps = pos[2][pos[2].size() - 1];
            ans -= (a[ps][2] - max(a[ps][1], a[ps][3]));
            pos[2].pop_back();
        }
    }

    if(cur == 3){
        sort(pos[3].begin(), pos[3].end(), cmp3);
        while(pos[3].size() > n / 2){
            int ps = pos[3][pos[3].size() - 1];
            ans -= (a[ps][3] - max(a[ps][2], a[ps][1]));
            pos[3].pop_back();
        }
    }

    cout << ans <<'\n';
}

int t;
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t --){
        init();
        work();
    }

    return 0;
}

