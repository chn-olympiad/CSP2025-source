#include<bits/stdc++.h>
using namespace std;
const int N = 100050;
int t, ans, cnt;
int b1=1, b2=1, b3=1;
struct manyi{
    int a,b,c;
    int flag = 0;
    int ma, mi, fff;
}peo[N];
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        int n;
        cin >> n ;
        for(int i = 1; i <= n; i++) {
            cin >> peo[i].a >> peo[i].b >> peo[i].c ;
            if(max(peo[i].a, max(peo[i].b, peo[i].c)) == peo[i].a) peo[i].ma = peo[i].a;
            else if(max(peo[i].a, max(peo[i].b, peo[i].c)) == peo[i].b) peo[i].ma = peo[i].b;
            else if(max(peo[i].a, max(peo[i].b, peo[i].c)) == peo[i].c) peo[i].ma = peo[i].c;
            if(min(peo[i].a, min(peo[i].b, peo[i].c)) == peo[i].a) peo[i].mi = peo[i].a;
            else if(min(peo[i].a, min(peo[i].b, peo[i].c)) == peo[i].b) peo[i].mi = peo[i].b;
            else if(min(peo[i].a, min(peo[i].b, peo[i].c)) == peo[i].c) peo[i].mi = peo[i].c;
            peo[i].fff = peo[i].a + peo[i].b+ peo[i].c-peo[i].ma- peo[i].mi;
        }
        ans = 0 ;
        cnt = 0 ;
        for(int i = 1; i <= n; i++){
            if(n == 2){
                if(peo[i + 1].b < peo[i].b && peo[i + 1].b < peo[i].ma && peo[i + 1].c < peo[i].c && peo[i + 1].c < peo[i+1].ma && peo[i].ma == peo[i].a ){
                    cnt += peo[i].fff + peo[i + 1].ma;
                }
            }
            else{
                if(b1 <= n/2){
                    if(peo[i].ma == peo[i].a){
                        b1++;
                        cnt += peo[i].a;
                        continue ;
                    }
                }
                if(b2 <= n/2){
                    if(peo[i].ma == peo[i].b){
                        b2++;
                        cnt += peo[i].b;
                        continue ;
                    }
                }
                if(b3 <= n/2){
                    if(peo[i].ma == peo[i].c){
                        b3++;
                        cnt += peo[i].c;
                        continue ;
                    }
                }
            }

        }
        ans = max(ans, cnt);
        cout << ans << endl;
    }
    return 0;
}
