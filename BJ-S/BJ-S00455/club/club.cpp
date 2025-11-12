#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int m[111111][5];

struct man{
    int a;
    int b;
    int c;
    int num;
};

man a[111111];
man b[111111];
man c[111111];
int la,lb,lc;
int ans;

bool abc(man x,man y){
    if( (x.a - max(x.b,x.c)) >= (y.a - max(y.b,y.c)) ){
        return 1;
    }
    return 0;
}

bool bac(man x,man y){
    if( (x.b - max(x.a,x.c)) >= (y.b - max(y.a,y.c)) ){
        return 1;
    }
    return 0;
}

bool cab(man x,man y){
    if( (x.c - max(x.a,x.b)) >= (y.c - max(y.a,y.b)) ){
        return 1;
    }
    return 0;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int p = 1;p <= t;p++){
        ans = la = lb = lc = 0;
        cin >> n;

        for(int i = 1;i <= n;i++){
            cin >> m[i][1] >> m[i][2] >> m[i][3];
            if(m[i][1] > m[i][2] && m[i][1] > m[i][3]){
                la++;
                a[la].a = m[i][1];
                a[la].b = m[i][2];
                a[la].c = m[i][3];

                a[la].num = i;
                //cout << i << " ";
            }
            else if(m[i][2] > m[i][1] && m[i][2] > m[i][3]){
                lb++;
                b[lb].a = m[i][1];
                b[lb].b = m[i][2];
                b[lb].c = m[i][3];

                b[lb].num = i;
                //cout << i << " ";
            }
            else if(m[i][3] > m[i][1] && m[i][3] > m[i][2]){
                lc++;
                c[lc].a = m[i][1];
                c[lc].b = m[i][2];
                c[lc].c = m[i][3];

                c[lc].num = i;
                //cout << i << " ";
            }
            else{
                ans = ans + max(max(m[i][1],m[i][2]),m[i][3]);
            }
        }

        if(la > (n / 2)){
            sort(a + 1,a + la + 1,abc);
            for(;la > (n / 2);la--){
                if(a[la].b > a[la].c){
                    ans = ans + a[la].b;
                }
                else{
                    ans = ans + a[la].c;
                }
            }
        }
        else if(lb > (n / 2)){
            sort(b + 1,b + lb + 1,bac);
            for(;lb > (n / 2);lb--){
                if(b[lb].a > b[lb].c){
                    ans = ans + b[lb].a;
                }
                else{
                    ans = ans + b[lb].c;
                }
            }
        }
        else if(lc > (n / 2)){
            sort(c + 1,c + lc + 1,cab);
            for(;lc > (n / 2);lc--){
                if(c[lc].a > c[lc].b){
                    ans = ans + c[lc].a;
                }
                else{
                    ans = ans + c[lc].b;
                }
            }
        }

        for(int i = 1;i <= la;i++){
            ans = ans + a[i].a;
            //cout << a[i].num << " ";
        }
        for(int i = 1;i <= lb;i++){
            ans = ans + b[i].b;
            //cout << b[i].num << " ";
        }
        for(int i = 1;i <= lc;i++){
            ans = ans + c[i].c;
            //cout << c[i].num << " ";
        }
    cout << ans << endl;
    }

    return 0;
}
