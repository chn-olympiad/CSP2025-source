#include<bits/stdc++.h>
using namespace std;
int t, n, cnt, ans;
bool v[100010];
struct idk{
    int x, y, z;
};
idk a[100010];
bool xx, yy, zz;
void shit(int k, int x, int y, int z){
    if(k == n + 1){
        ans = max(ans, cnt);
        return;
    }
    v[k] = true;
    if(x < n / 2){
        cnt += a[k].x;
        shit(k + 1, x + 1, y, z);
        cnt -= a[k].x;
    }
    if(y < n / 2){
        cnt += a[k].y;
        shit(k + 1, x, y + 1, z);
        cnt -= a[k].y;
    }
    if(z < n / 2){
        cnt += a[k].z;
        shit(k + 1, x, y, z + 1);
        cnt -= a[k].z;
    }
    v[k] = false;
    return;
}
bool cmpx(idk x, idk y){
    return x.x > y.x;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        xx = false; yy = false; zz = false;
        ans = 0; cnt = 0;
        for(int i = 1; i <= n; i++) {
            v[i] = false;
        }
        for(int i = 1; i <= n; i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x != 0) xx = true;
            if(a[i].y != 0) yy = true;
            if(a[i].z != 0) zz = true;
        }
        //shit(1, 0, 0, 0);
        //cout<<ans<<'\n';
        if((xx && yy && zz) || n <= 20){
           shit(1, 0, 0, 0);
           cout<<ans<<'\n';
        }
        else if(!yy && !zz){
            sort(a + 1, a + n + 1, cmpx);
            for(int i = 1; i <= n / 2; i++){
                ans += a[i].x;
            }
            cout<<ans<<'\n';

        }
        else{
            cout<<"oh shit\n"<<endl;
        }
    }
    return 0;
}
