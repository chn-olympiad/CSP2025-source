#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int t;
int n;
int vis[maxn];

struct pe{
    int a, b, c;
    int id;
}p[maxn];


bool cmp1(pe x, pe y){
    return x.a - x.b > y.a - y.b;
}

struct wk {
    int w;
    int tag;
    int id;
    friend bool operator < (wk x, wk y){
    return x.w < y.w;
    }
};
priority_queue<wk> qu;


int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        //cout <<"-----------------"<<endl;
        cin >> n;
        ll ans =0 ;
        int l1 = 0, l2 = 0, l3 = 0;
        int kkksc = 0;
        while(!qu.empty()) qu.pop();
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            cin >>p[i].a >>p[i].b >>p[i].c ;
            p[i].id = i;
        }
        sort(p + 1, p + 1 + n, cmp1);

        for(int i = 1; i <= n; i++){
            wk tmp;
            if(p[i].a - p[i].b >= 0) {
                tmp = {p[i].c - p[i].a, 13, p[i].id};
            }
            else tmp = {p[i].c - p[i].b, 23, p[i].id};
            qu.push(tmp);
        }

        while(!qu.empty()){
            wk tmp = qu.top();qu.pop();
            //printf("qu: %d %d %d\n", tmp.id, vis[tmp.id], tmp.w);
            if(tmp.w < 0) continue;
            if(vis[tmp.id]) continue;
            if(l3 >= n/2) continue;
            vis[tmp.id] = 3;
            l3++;
        }
        for(int i = 1; i <= n; i++){
            if(l1 >= n/2) break;
            if(p[i].a - p[i].b >= 0 && !vis[p[i].id]){
                l1++;
                vis[p[i].id] = 1;
            }
        }
        for(int i = n; i; i--){
            if(l2 >= n/2) break;
            if(p[i].a - p[i].b < 0 && !vis[p[i].id]){
                l2++;
                vis[p[i].id] = 2;
            }
        }
        for(int i = 1; i <= n; i++){
            if(!vis[p[i].id]){
                if(l1 < n/2){
                    l1++;
                    vis[p[i].id] = 1;
                }
                else if(l2 < n/2){
                    l2++;
                    vis[p[i].id] = 2;
                }
                else if(l3 < n/2){
                    l3++;
                    vis[p[i].id] = 3;
                }
                else kkksc = -1;
            }
        }
        for(int i = 1; i <= n; i++){
            pe tmp = p[i];
            if(vis[tmp.id] == 1) ans += tmp.a;
            else if(vis[tmp.id] == 2) ans += tmp.b;
            else ans += tmp.c;
            //printf("select: %d %d %d %d %d\n", tmp.id, vis[tmp.id], tmp.a, tmp.b, tmp.c );
        }




        cout << ans <<endl;

    }


    return 0;
}
