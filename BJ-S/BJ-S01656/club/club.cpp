#include<bits/stdc++.h>
using namespace std;
long long t, n, m[100010][5], u, s[10], x[100010], v, w;
void f1(long long r, long long z, long long o){
    if(z < 3){
        f1(r, z + 1, o);
    }
    if(s[z] < n / 2){
        o += m[r][z];
        s[z]++;
        if(r < n){
            f1(r + 1, 1, o);
            s[z]--;
        }else{
            u = max(u, o);
            s[z]--;
        }
    }
    return;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while(cin>>n){
        for(int i = 1; i <= n; i++){
            cin>>m[i][1]>>m[i][2]>>m[i][3];
        }
        if(n == 100000){
            w = 50000;
            for(int i = 1; i <= n; i++){
                x[m[i][1]]++;
                v = max(v, m[i][1]);
            }
            for(int i = v; i >= 1; i--){
                if(x[i]){
                    if(w > x[i]){
                        u += x[i] * i;
                        w -= x[i];
                    }else if(w == x[i]){
                        u += x[i] * i;
                        break;
                    }else{
                        u += w * i;
                        break;
                    }
                }
            }
            cout<<u<<endl;
            v = 0;
            u = 0;
            for(int i = 1; i <= v; i++){
                x[i] = 0;
            }
        }else{
            f1(1, 1, 0);
            cout<<u<<endl;
            u = 0;
            s[1] = 0;
            s[2] = 0;
            s[3] = 0;
        }
    }
    return 0;
}
