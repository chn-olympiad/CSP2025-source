#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6+10;
struct l{
    long long di,id,l;
} a[N];
bool cmp(l x,l y){
    return x.di > y.di;
}
long long T,n,ans,k,cnt,d1,d2,d3,vis[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        for(long long i = 1;i <= n;i++){
            cin >> k;
            a[++cnt].di = k;
            a[cnt].id = 1;
            a[cnt].l = i;
            cin >> k;
            a[++cnt].di = k;
            a[cnt].id = 2;
            a[cnt].l = i;
            cin >> k;
            a[++cnt].di = k;
            a[cnt].id = 3;
            a[cnt].l = i;

        }
        sort(a+1,a+1+cnt,cmp);
        for(long long i = 1;i <= 3*n;i++) {cout << a[i].di << " " <<a[i].id<<" " << a[i].l << endl;}
        for(long long i = 1;i <= 3*n;i++){
            if(a[i].id == 1){
                if(d1 < n/2 && vis[a[i].l] == 0){
                    ans += a[i].di;
                    d1++;
                    vis[a[i].l] = 1;
                    //cout << a[i].di << " " << a[i].l << endl;
                }
                else continue;
            }
            if(a[i].id == 2){
                if(d2 < n/2  && vis[a[i].l] == 0){
                    ans += a[i].di;
                    d2++;
                    vis[a[i].l] = 1;
                    //cout << a[i].di << " " << a[i].l << endl;
                }
                else continue;
            }
            if(a[i].id == 3){
                if(d3 < n/2 && vis[a[i].l] == 0){
                    ans += a[i].di;
                    d3++;
                    vis[a[i].l] = 1;
                    //cout << a[i].di << " " << a[i].l << endl;
                }
                else continue;
            }
        }
        cout << ans << endl;
        d1 = 0;
        d2 = 0;
        d3 = 0;
        ans = 0;
        cnt = 0;
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
    }
    return 0;
}
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
