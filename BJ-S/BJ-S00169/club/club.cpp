#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int T,n;

struct peo{
    int a,b,c;
    bool fa,fb,fc;
}p[N];

bool cmp_a(peo a1,peo b1){
    if(a1.a != b1.a) return a1.a > b1.a;
    else return (a1.b + a1.c) < (b1.b + b1.c);
}

bool cmp_b(peo a1,peo b1){
    if(a1.b != b1.b) return a1.b > b1.b;
    else return (a1.a + a1.c) < (b1.a + b1.c);
}

bool cmp_c(peo a1,peo b1){
    if(a1.c != b1.c) return a1.c > b1.c;
    else return (a1.b + a1.a) < (b1.b + b1.a);
}

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> T;
    while(T--){
        int ans = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> p[i].a >> p[i].b >> p[i].c;
            p[i].fa = 0;
            p[i].fb = 0;
            p[i].fc = 0;
        }
        sort(p,p+n,cmp_a);
        for(int i = 0; i < n / 2; i++) p[i].fa = 1;
        sort(p,p+n,cmp_b);
        for(int i = 0; i < n / 2; i++) p[i].fb = 1;
        sort(p,p+n,cmp_c);
        for(int i = 0; i < n / 2; i++) p[i].fc = 1;
        for(int i = 0; i < n; i++) ans += max(max(p[i].a * p[i].fa , p[i].b * p[i].fb) , p[i].c * p[i].fc);
        cout << ans << endl;
    }

    return 0;
}
