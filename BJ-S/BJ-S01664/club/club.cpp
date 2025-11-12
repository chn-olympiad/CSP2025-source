#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n, k[3];

struct Sat{
    int x, y, xid, dif;
}a[N];
bool cmpa(Sat a1, Sat a2){
    return a1.dif < a2.dif;
}

struct Like{
    int s, id;
}b[4];
bool cmpb(Like x, Like y){
    return x.s > y.s;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T; cin >> T;
    while(T--){
        cin >> n;
        k[1] = k[2] = k[3] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=3; j++){
                cin >> b[j].s;
                b[j].id = j;
            }
            sort(b + 1, b + 4, cmpb);
            a[i].x = b[1].s, a[i].y = b[2].s;
            k[b[1].id]++, a[i].xid = b[1].id;
            a[i].dif = a[i].x - a[i].y;
        }
        sort(a + 1, a + n + 1, cmpa);

        int ans = 0; bool flag = 1;
        for(int i=1; i<=3; i++){
            if(k[i] > n / 2){
                flag = 0;
                int rem = k[i] - n / 2, j;
                for(j=1; j<=n; j++){
                    if(a[j].xid != i) continue;
                    // Same id, Go out!
                    if(rem){
                        ans += a[j].y;
                        rem--;
                    }
                    else{
                        ans += a[j].x;
                    }
                }
                for(j=1; j<=n; j++){
                    if(a[j].xid == i) continue;
                    ans += a[j].x;
                }
                break;
            }
        }

        if(flag){
            for(int i=1; i<=n; i++)
                ans += a[i].x;
        }

        cout << ans << '\n';
    }
    
    return 0;
}
