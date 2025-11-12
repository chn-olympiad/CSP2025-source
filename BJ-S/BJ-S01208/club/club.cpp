#include <bits/stdc++.h>
#define int long long
using namespace std;
struct peo{
    int l1,l2,l3,mx,hat;
}a[100005];
int t,n,hat[4],ans;
int annoying;
void input(){
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i].l1 >> a[i].l2 >> a[i].l3;
        a[i].mx = max(a[i].l1,max(a[i].l2,a[i].l3));
        if(a[i].mx == a[i].l1)a[i].hat = 1;
        if(a[i].mx == a[i].l2)a[i].hat = 2;
        if(a[i].mx == a[i].l3)a[i].hat = 3;
    }
}
bool cmp1(peo c,peo b){
    return c.mx > b.mx;
}
int find_min(peo c){//寻找第二喜欢的 不需要第三喜欢因为排不到那里
    int d[4];
    d[1] =c.l1;
    d[2] = c.l2;
    d[3] = c.l3;
    sort(d+1,d+4);
    return c.mx - d[2];
}
bool cmp2(peo c,peo b){
    int dc = find_min(c),db = find_min(b);
    return dc < db;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        input();
        ans = 0;
        memset(hat,0,sizeof(hat));
        sort(a+1,a+n+1,cmp1);
        for(int i = 1;i <= n;++i){
            ans += a[i].mx;
            hat[a[i].hat]++;
        }
        //暴力完成 开始处理方案
        if(hat[1]>n/2)annoying = 1;
        if(hat[2]>n/2)annoying = 2;
        if(hat[3]>n/2)annoying = 3;
        //cout << annoying << endl;
        if(annoying){
            sort(a+1,a+n+1,cmp2);
            for(int i = 1;hat[annoying]>n/2;++i){
                if(a[i].hat!=annoying)continue;
                ans -= find_min(a[i]);
                --hat[annoying];
            }
            /*for(int i = 1;i <= n;++i){
                cout << a[i].l1 << ' ' << a[i].l2 << ' ' << a[i].l3 << endl;
            }*/
            //cout << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
