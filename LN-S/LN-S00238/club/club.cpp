/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ll T;

    cin >> T;

    while(T--){

        ll n, ans = 0;
        ll a[100005][3];
        int to[100005], cnt[3] = {0, 0, 0};

        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            ll m = max(a[i][0], max(a[i][1], a[i][2]));
            ans += m;
            if(m == a[i][0]){to[i] = 0;cnt[0]++;}
            else if(m == a[i][1]){to[i] = 1;cnt[1]++;}
            else {to[i] = 2;cnt[2]++;}
            int t = a[i][to[i]];
            for(int j = 0; j < 3; j++) a[i][j] -= t;
        }

        if(n == 2 && to[0] == to[1]){
            ll ccf = -999999;
            for(int i = 0; i < 3; i++){
                if(a[0][i] == 0) continue;
                ccf = max(ccf, a[0][i]);
            }
            for(int i = 0; i < 3; i++){
                if(a[1][i] == 0) continue;
                ccf = max(ccf, a[1][i]);
            }
            ans += ccf;
        }

        queue<int> q;
        do{
            while(cnt[0] > n/2 || cnt[1] > n/2 || cnt[2] > n/2){
                q.push()
            }
        }while(q.empty());

        cout << ans << endl;

    }

    return 0;
}
*/
/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ll T;

    cin >> T;

    while(T--){

        ll n, ans = 0;
        ll a[100005][3];
        priority_queue<int> d1, d2, d3;

        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            ll m = max(a[i][0], max(a[i][1], a[i][2]));
            if(m == a[i][0]){

            }
        }

    }

    return 0;
}
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct person{
    ll a[3];
    int to;
} p[100005];

ll n, T;
int f = -1;

bool cmp(person a, person b){
    if(a.to == f && b.to != f) return 1;
    if(a.to != f && b.to != f) return 0;
    ll am = -999999, bm = -999999;
    for(int j = 0; j < 3; j++){
        if(a.a[j] < 0) am = max(am, a.a[j]);
        if(b.a[j] < 0) bm = max(bm, b.a[j]);
    }
    return am > bm;
}

int main(){

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> T;

    while(T--){

        ll ans = 0;
        int cnt[3] = {0, 0, 0};

        cin >> n;

        for(int i = 0 ; i < n; i++){
            cin >> p[i].a[0] >> p[i].a[1] >> p[i].a[2];
            ll m = max(p[i].a[0], max(p[i].a[1], p[i].a[2]));
            ans += m;
            if(m == p[i].a[0]) {p[i].to = 0; cnt[0]++;}
            else if(m == p[i].a[1]) {p[i].to = 1; cnt[1]++;}
            else {p[i].to = 2; cnt[2]++;}
            int t = p[i].a[p[i].to];
            for(int j = 0; j < 3; j++) p[i].a[j] -= t;
        }

        //queue<int> q;
            //cout << "here" << endl;
        while(cnt[0] > n/2 || cnt[1] > n/2 || cnt[2] > n/2){
            f = (cnt[0] > n/2 ? 0 : (cnt[1] > n/2 ? 1 : 2));
            sort(p, p+n-1, cmp);
            int i = 0;
            while(cnt[f] > n/2){
                //q.push(i++);
                //printf("got %d -> q;\n", q.back());
                cnt[f]--;
/*
            }
            //cout << q.front() << endl;
            while(!q.empty()){
*/
                int now = i;
                i++;
                //int now = q.front();
                //q.pop();
                //printf("changer got %d;\t", now);
                ll nm = -999999;
                int tonew = -1;
                for(int j = 0; j < 3; j++) if(p[now].a[j] < 0 && nm < p[now].a[j]){nm = p[now].a[j]; tonew = j;}
                //printf("the '%d' changed %d -> %d\n", now, p[now].to, tonew);
                if(tonew != -1){p[now].to = tonew; for(int j = 0; j < 3; j++) p[now].a[j] -= nm;}
                else cnt[p[now].to]++;
                ans += nm;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
