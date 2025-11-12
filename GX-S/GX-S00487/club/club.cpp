#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int maxa , maxb , maxc;
struct node{
    int a , b , c;
    bool flag;
}xs[MAXN];
bool cmp(node x ,node y){
    if(x.a!=y.a)return x.a > y.a;
    else if(x.b!=y.b)return x.b > y.b;
    else return x.c > y.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        int suma = 0 , sumb = 0 , sumc = 0;
        int ra = 0 , rb = 0 , rc = 0;
        for(int i = 1 ; i <= n ; i++){
            cin >> xs[i].a >> xs[i].b >> xs[i].c;
            xs[i].flag = false;
        }

        sort(xs+1,xs+n+1,cmp);
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(!xs[j].flag && xs[j].a >= xs[j].b &&xs[j].a >= xs[j].c && ra < n / 2){
                    suma += xs[j].a;
                    xs[j].flag = true;
                    ra++;
                }else if(!xs[j].flag && xs[j].b >= xs[j].a &&xs[j].b >= xs[j].c && rb < n / 2){
                    sumb += xs[j].b;
                    xs[j].flag = true;
                    rb++;
                }else if(!xs[j].flag && xs[j].c >= xs[j].a &&xs[j].c >= xs[j].b && rc < n / 2){
                    sumc += xs[j].c;
                    xs[j].flag = true;
                    rc++;
                }
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if(xs[i].flag)continue;
            else{
                int x[4];
                x[1] = xs[i].a , x[2] = xs[i].b , x[3] = xs[i].c;
                sort(x+1,x+4);
                if(x[3] == xs[i].a && ra <= n / 2){
                    suma += xs[i].a;
                    xs[i].flag = true;
                    ra++;
                }else if(x[3] == xs[i].b && rb < n / 2){
                    sumb += xs[i].b;
                    xs[i].flag = true;
                    rb++;
                }else if(x[3] == xs[i].c && rc < n / 2){
                    sumc += xs[i].c;
                    xs[i].flag = true;
                    rc++;
                }else if(x[2] == xs[i].a && ra < n / 2){
                    suma += xs[i].a;
                    xs[i].flag = true;
                    ra++;
                }else if(x[2] == xs[i].b && rb < n / 2){
                    sumb += xs[i].b;
                    xs[i].flag = true;
                    rb++;
                }else if(x[2] == xs[i].c && rc < n / 2){
                    sumc += xs[i].c;
                    xs[i].flag = true;
                    rc++;
                }else if(x[1] == xs[i].a && ra < n / 2){
                    suma += xs[i].a;
                    xs[i].flag = true;
                    ra++;
                }else if(x[1] == xs[i].b && rb < n / 2){
                    sumb += xs[i].b;
                    xs[i].flag = true;
                    rb++;
                }else {
                    sumc += xs[i].c;
                    xs[i].flag = true;
                    rc++;
                }
            }
        }
        cout << suma + sumb +sumc;
    }
    return 0;
}
