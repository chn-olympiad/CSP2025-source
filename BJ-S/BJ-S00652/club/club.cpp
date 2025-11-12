#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;
const int N = 1e5+5;
int T, n;
struct lik{ int a, b, c; int id; }a[N];

bool cmp1(lik x, lik y){
    int xx = min(x.a-x.b, x.a-x.c);
    int yy = min(y.a-y.b, y.a-y.c);
    return xx>yy;
}

bool cmp2(lik x, lik y){
    int xx = x.b-x.c;
    int yy = y.b-y.c;
    return xx>yy;
}

bool cmp3(lik x, lik y){
    int xx = min(x.c-x.b, x.c-x.a);
    int yy = min(y.c-y.b, y.c-y.a);
    return xx>yy;
}

void prt(){
    cout<<"prt()======="<<endl;
    for (int i=1; i<=n; i++){
        cout<<a[i].id<<" ";
    }
    cout<<endl;
}

void solve(){
    int fa, fb;
    int ans=0;
    sort(a+1, a+1+n, cmp1);
//    prt();
    int ena=(n>>1);
//    cout<<"a: ";
    for (int i=1; i<=(n>>1); i++){
        int x = min(a[i].a-a[i].b, a[i].a-a[i].c);
        if (x<0){
            ena = i-1;
            fa=0;
            break;
        }
//        cout<<a[i].id<<" ";
        ans += a[i].a;
    }
//    cout<<endl<<ena<<endl;
    fa=ena;
    sort(a+1+ena, a+1+n, cmp2);
//    prt();
    int enb=min(ena+(n>>1), n);
//    cout<<"b: ";
    for (int i=ena+1; i<=enb; i++){
        int x= a[i].b-a[i].c;
        if (x<0){
            enb = i-1;
            fb=0;
            break;
        }
//        cout<<a[i].id<<" ";
        ans += a[i].b;
    }
//    cout<<endl<<enb<<endl;
    fb=enb-ena;
    if (enb==n){
        printf("%d\n", ans);
        return;
    }
    if (enb>=(n>>1)){
        for (int i=enb+1; i<=n; i++){
            ans += a[i].c;
        }
        printf("%d\n", ans);
        return;
    }
    sort(a+1+enb, a+1+n, cmp3);
//    prt();
    int enc=min(enb+(n>>1), n);
//    cout<<"c: "<<endl;
    for (int i=enb+1; i<=enc; i++){
        int x = min(a[i].c-a[i].a, a[i].c-a[i].b);
        if (x<0){
            enc=i-1;
            break;
        }
//        cout<<a[i].id<<" ";
        ans += a[i].c;
    }
//    cout<<endl<<enc<<endl;
    if (enc==n){
        printf("%d\n", ans);
        return;
    }
    for (int i=enc+1; i<=n; i++){
        if (fb==(n>>1)||(fa<(n>>1)&&a[i].a>=a[i].b)){
            fa++, ans+=a[i].a;
//            cout<<"a: "<<a[i].id<<endl;
        }
        if (fa==(n>>1)||(fb<(n>>1)&&a[i].a<=a[i].b)){
            fb++, ans+=a[i].b;
//            cout<<"b: "<<a[i].id<<endl;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
            a[i].id=i;
        }
        solve();
    }
    return 0;
}
