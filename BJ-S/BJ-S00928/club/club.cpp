#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Num{
    int w, n;
};

bool operator<(const Num& x, const Num& y)
{ return x.w > y.w; }

int t, n, a[100005][5], ans;
queue<int> Q;
priority_queue<Num> q[10];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            Q.push(i);
            for(int j=1; j<=3; j++){
                cin >> a[i][j];
            }
        }
        ans = 0;
        while(!Q.empty()){
            int i = Q.front();
            Q.pop();
            int tmp=0;
            int maxn = 0, s;
            for(int j=1; j<=3; j++){
                int w = a[i][j];
                if(q[j].size() < n/2){
                    if(w > maxn){
                        maxn = w;
                        s = j;
                        tmp = 0;
                    }
                }
                else{
                    int f=q[j].top().w, s=q[j].top().n;
                    if(w > f){
                        if(w-f > maxn){
                            maxn = w-f;
                            s = j;
                            tmp = s;
                        }
                    }
                }
            }
            if(tmp == 0){
                q[s].push({a[i][s], i});
                ans += maxn;
            }
            else{
                Q.push(tmp);
                q[s].pop();
                q[s].push({a[i][s], i});
                ans += maxn;
            }
        }
        cout << ans << endl;
        for(int i=1; i<=3; i++){
            while(!q[i].empty()) q[i].pop();
        }
    }
    return 0;
}
