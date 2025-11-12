#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define qwertyuiop pair <pair <int, int>, int>
const int N = 100010;

int n, t, a[N][5], to[N][5], no, ma[N];
int sz[5];
bool try_[5];
priority_queue <qwertyuiop/*, vector <qwertyuiop>, greater <qwertyuiop>*/> q[5]; // val & id

int getmax (int x) {
    int maa = max ({a[x][1], a[x][2], a[x][3]});
    if (maa == a[x][1]) return 1;
    if (maa == a[x][2]) return 2;
    if (maa == a[x][3]) return 3;
}

int getmaxx () {
    int maa = max ({sz[1], sz[2], sz[3]});
    if (maa == sz[1]) return 1;
    if (maa == sz[2]) return 2;
    if (maa == sz[3]) return 3;
}

void getto (int x) {
    to[x][1] = a[x][1] - a[x][ma[x]];
    to[x][2] = a[x][2] - a[x][ma[x]];
    to[x][3] = a[x][3] - a[x][ma[x]];
}

void pushh (int x) {
    if (ma[x] == 1)
        // printf("-->i push %d, %d, x = %d. \n", to[x][1], max (to[x][2], to[x][3]), x);
        q[1].push (mp (mp (to[x][1], max (to[x][2], to[x][3])), x));
    if (ma[x] == 2) 
        q[2].push (mp (mp (to[x][2], max (to[x][1], to[x][3])), x));
    if (ma[x] == 3) 
        q[3].push (mp (mp (to[x][3], max (to[x][1], to[x][2])), x));
}

int next (int x) {
    if (x == 1) {
        return 2;
    } return 1;
} int nextnext (int x) {
    if (x == 3) {
        return 2;
    } return 3;
}

void change (int now) {
    try_[now] = true;
    while (sz[now] > no) {
        int x = q[now].top ().se; q[now].pop (); sz[now] --;
        // printf("in %d, now is x = %d, to = %d, %d, %d. \n", now, x, to[x][1], to[x][2], to[x][3]);
        int _ = ma[x];
        int __ = next(ma[x]);
        int ___ = nextnext(ma[x]);
        int better = to[x][__] > to[x][___]? __: ___;
        if (try_[better]) {
            // printf("damn, change!!!!!");
            better = to[x][__] > to[x][___]? ___: __;
        }
        // printf("id%d, better = %d. \n", x, better);
        ma[x] = better;
        getto (x);
        pushh (x);
        sz[better] ++;
    }  

    while (!q[now].empty ()) {
        int x = q[now].top ().se; q[now].pop ();
        // printf(":::in %d, now is x = %d, to = %d, %d, %d. \n", now, x, to[x][1], to[x][2], to[x][3]);
    }
}

int main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    scanf("%d", &t);
    while (t --) {
        sz[1] = sz[2] = sz[3] = 0;
        try_[1] = try_[2] = try_[3] = false;
        while (! q[1].empty()) q[1].pop(); while (! q[2].empty()) q[2].pop(); while (! q[2].empty()) q[2].pop();
        scanf("%d", &n); no = n / 2;
        for (int i = 1; i <= n; i ++) {
            scanf("%d%d%d", a[i] + 1, a[i] + 2, a[i] + 3);
            ma[i] = getmax (i);
            getto (i);
            pushh (i);
            sz[ma[i]] ++;
        }
        int _ = getmaxx ();
        // printf("max = %d; no = %d; \n", _, no);
        change (_);
        if (_ == 1) {
            change (max (sz[2], sz[3]) == sz[2]? 2: 3);
            change (min (sz[2], sz[3]) == sz[2]? 3: 2);
        } if (_ == 2) {
            change (max (sz[1], sz[3]) == sz[1]? 1: 3);
            change (min (sz[1], sz[3]) == sz[1]? 3: 1);
        } if (_ == 2) {
            change (max (sz[1], sz[2]) == sz[1]? 1: 2);
            change (min (sz[1], sz[2]) == sz[1]? 2: 1);
        }

        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            // printf("%d ", ma[i]);
            ans += a[i][ma[i]];
        }
        printf("%d\n", ans);
        // printf("-------------\n");
    }
    
    
    return 0;
}

/*

进食后入：
十年oi一场空，不开longlong见祖宗！
关于spfa，他死了


#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define qwertyuiop pair <pair <pair <int, int>, int>, int>
const int N = 100010;

int n, t, a[N][5], to[N][5], no, ma[N];
int sz[5];
bool try_[5];
priority_queue <qwertyuiop, vector <qwertyuiop>, greater <qwertyuiop>> q[5]; // val & id

int getmax (int x) {
    int maa = max ({a[x][1], a[x][2], a[x][3]});
    if (maa == a[x][1]) return 1;
    if (maa == a[x][2]) return 2;
    if (maa == a[x][3]) return 3;
}

int getmaxx () {
    int maa = max ({sz[1], sz[2], sz[3]});
    if (maa == sz[1]) return 1;
    if (maa == sz[2]) return 2;
    if (maa == sz[3]) return 3;
}

void getto (int x) {
    to[x][1] = a[x][1] - a[x][ma[x]];
    to[x][2] = a[x][2] - a[x][ma[x]];
    to[x][3] = a[x][3] - a[x][ma[x]];
}

void pushh (int x) {
    if (ma[x] == 1) 
        q[1].push (mp (mp (mp (a[x][1], to[x][2]), to[x][3]), x));
    if (ma[x] == 2) 
        q[2].push (mp (mp (mp (a[x][2], to[x][1]), to[x][3]), x));
    if (ma[x] == 3) 
        q[3].push (mp (mp (mp (a[x][3], to[x][1]), to[x][2]), x));
}

int next (int x) {
    if (x == 1) {
        return 2;
    } return 1;
} int nextnext (int x) {
    if (x == 3) {
        return 2;
    } return 3;
}

void change (int now) {
    try_[now] = true;
    while (sz[now] > no) {
        int x = q[now].top ().se; q[now].pop (); sz[now] --;
        int _ = ma[x];
        int __ = next(ma[x]);
        int ___ = nextnext(ma[x]);
        int better = to[x][__] > to[x][___]? __: ___;
        if (try_[better]) {
            // printf("damn, change!!!!!");
            better = to[x][__] > to[x][___]? ___: __;
        }
        // printf("id%d, better = %d. ", x, better);
        ma[x] = better;
        pushh (x);
        sz[better] ++;
        getto (now);
    }  
}

int main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    scanf("%d", &t);
    while (t --) {
        sz[1] = sz[2] = sz[3] = 0;
        try_[1] = try_[2] = try_[3] = false;
        while (! q[1].empty()) q[1].pop(); while (! q[2].empty()) q[2].pop(); while (! q[2].empty()) q[2].pop();
        scanf("%d", &n); no = n / 2;
        for (int i = 1; i <= n; i ++) {
            scanf("%d%d%d", a[i] + 1, a[i] + 2, a[i] + 3);
            ma[i] = getmax (i);
            pushh (i);
            sz[ma[i]] ++;
            getto (i);
        }
        int _ = getmaxx ();
        // printf("max = %d; no = %d; ", _, no);
        change (_);
        if (_ == 1) {
            change (max (sz[2], sz[3]) == sz[2]? 2: 3);
            change (min (sz[2], sz[3]) == sz[2]? 3: 2);
        } if (_ == 2) {
            change (max (sz[1], sz[3]) == sz[1]? 1: 3);
            change (min (sz[1], sz[3]) == sz[1]? 3: 1);
        } if (_ == 2) {
            change (max (sz[1], sz[2]) == sz[1]? 1: 2);
            change (min (sz[1], sz[2]) == sz[1]? 2: 1);
        }

        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            // printf("%d ", ma[i]);
            ans += a[i][ma[i]];
        }
        printf("%d\n", ans);
        // printf("-------------\n");
    }
    
    
    return 0;
}
*/