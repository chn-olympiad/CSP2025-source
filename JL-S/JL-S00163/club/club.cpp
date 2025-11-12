#include<bits/stdc++.h>

using namespace std;
struct N{
    int a;
    int b;
    int c;
};
int maxx(int a, int b, int c){return max(max(a, b), c);}
int midd(int a, int b, int c){
    if(b >= a && a >= c) return a;
    if(c >= a && a >= b) return a;
    if(c >= b && b >= a) return b;
    if(a >= b && b >= c) return b;
    return c;
}
int minn(int a, int b, int c){return min(min(a, b), c);}
bool cmp(N x, N y){
    int xmx = maxx(x.a, x.b, x.c), xmd = midd(x.a, x.b, x.c);
    int ymx = maxx(y.a, y.b, y.c), ymd = midd(y.a, y.b, y.c);
    if(xmx - xmd != ymx - ymd) return xmx - xmd > ymx - ymd;
    return xmd - minn(x.a, x.b, x.c) > ymd - minn(y.a, y.b, y.c);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        int cnt = 0;
        scanf("%d", &n);
        vector<N> lis(n + 1);
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d",&lis[i].a,&lis[i].b,&lis[i].c);
        }
        sort(lis.begin() + 1, lis.end(), cmp);
        int ca = n / 2, cb = n / 2, cc = n / 2;
        for(int i = 1; i <= n; i++){
            int a = lis[i].a, b = lis[i].b, c = lis[i].c;
            if(a >= b && a >= c){
                if(ca){ca--; cnt += a;}
                else if(b >= c && cb){cb--; cnt += b;}
                else{cc--; cnt += c;}
            }
            else if(b >= a && b >= c){
                if(cb){cb--; cnt += b;}
                else if(a >= c && ca){ca--; cnt += a;}
                else{cc--; cnt += c;}
            }
            else{
                if(cc){cc--; cnt += c;}
                else if(b >= a && cb){cb--; cnt += b;}
                else{ca--; cnt += a;}
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
