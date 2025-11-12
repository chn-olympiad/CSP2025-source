#include<bits/stdc++.h>
using namespace std;
struct f_kinds{
    int a1,a2,a3,val;
}f[100010][4];
struct members{
    int a1,a2,a3;
}a[100010];
bool cmp(members x,members y){
    if(x.a1 == y.a1){
        if(x.a2 == y.a2) return x.a3 >= y.a3;
        return x.a2 > y.a2;
    }
    return x.a1 > y.a1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T,n;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
        sort(a+1,a+n+1,cmp);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++) f[i][j].a1 = 0,f[i][j].a2 = 0,f[i][j].a3 = 0,f[i][j].val = 0;
            int j = 1;
            if(f[i-1][j].a1 < n / 2){
                if(f[i-1][j].val + a[i].a1 >= f[i][j-1].val){
                    f[i][j].val = f[i-1][j].val + a[i].a1;
                    f[i][j].a1 = f[i-1][j].a1 + 1;
                    f[i][j].a2 = f[i-1][j].a2,f[i][j].a3 = f[i-1][j].a3;
                }else{
                    f[i][j].val = f[i][j-1].val;
                    f[i][j].a1 = f[i][j-1].a1;
                    f[i][j].a2 = f[i][j-1].a2;
                    f[i][j].a3 = f[i][j-1].a3;
                }
            }else{
                f[i][j].val = f[i-1][j].val;
                f[i][j].a1 = f[i-1][j].a1;
                f[i][j].a2 = f[i-1][j].a2;
                f[i][j].a3 = f[i-1][j].a3;
            }
            j = 2;
            if(f[i-1][j].a2 < n / 2){
                if(f[i-1][j].val + a[i].a2 >= f[i][j-1].val){
                    f[i][j].val = f[i-1][j].val + a[i].a2;
                    f[i][j].a2 = f[i-1][j].a2 + 1;
                    f[i][j].a1 = f[i-1][j].a1,f[i][j].a3 = f[i-1][j].a3;
                }else{
                    f[i][j].val = f[i][j-1].val;
                    f[i][j].a1 = f[i][j-1].a1;
                    f[i][j].a2 = f[i][j-1].a2;
                    f[i][j].a3 = f[i][j-1].a3;
                }
            }else{
                f[i][j].val = f[i-1][j].val;
                f[i][j].a1 = f[i-1][j].a1;
                f[i][j].a2 = f[i-1][j].a2;
                f[i][j].a3 = f[i-1][j].a3;
            }
            j = 3;
            if(f[i-1][j].a3 < n / 2){
                if(f[i-1][j].val + a[i].a3 >= f[i][j-1].val){
                    f[i][j].val = f[i-1][j].val + a[i].a3;
                    f[i][j].a3 = f[i-1][j].a3 + 1;
                    f[i][j].a1 = f[i-1][j].a1,f[i][j].a2 = f[i-1][j].a2;
                }else{
                    f[i][j].val = f[i][j-1].val;
                    f[i][j].a1 = f[i][j-1].a1;
                    f[i][j].a2 = f[i][j-1].a2;
                    f[i][j].a3 = f[i][j-1].a3;
                }
            }else{
                f[i][j].val = f[i-1][j].val;
                f[i][j].a1 = f[i-1][j].a1;
                f[i][j].a2 = f[i-1][j].a2;
                f[i][j].a3 = f[i-1][j].a3;
            }
        }
        cout << f[n][3].val << "\n";
    }
    return 0;
}
