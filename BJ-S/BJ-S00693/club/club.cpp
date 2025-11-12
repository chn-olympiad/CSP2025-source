#include <bits/stdc++.h>
using namespace std;
struct t{
    int a;
    bool b;
};
t a[1000002];
t b[1000002];
t c[1000002];
int sum[10000002];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int cont;
    cin>>cont;
    for(int j=1;j<=cont;j++){
    int n;
    cin>>n;
    int ka=0,kb=0,kc=0,ba=0,bb=0,bc=0;
    int num = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>b[i].a>>c[i].a;
        ka+=a[i].a;
        kb+=b[i].a;
        kc+=c[i].a;
        a[i].b=0;
        b[i].b=0;
        b[i].b=0;
    }
    ka = ka/n;
    kb = kb/n;
    kc = kc/n;
    for(int i=1;i<=n;i++){
        if(ka<a[i].a&&ba<=n/2&&num<=n&&a[i].b==0) {
            ba++;
            sum[j]+=a[i].a;
            num++;
            a[i].b=1;
            b[i].b=1;
            c[i].b=1;
        }
        if(kb<b[i].a&&bb<=n/2&&num<=n&&b[i].b==0) {
            bb++;
            sum[j]+=b[i].a;
            num++;
            a[i].b=1;
            b[i].b=1;
            c[i].b=1;
        }
        if(kc<c[i].a&&bc<=n/2&&num<=n&&c[i].b==0) {
            bc++;
            sum[j]+=c[i].a;
            num++;
            a[i].b=1;
            b[i].b=1;
            c[i].b=1;
        }
    }
    }
    for(int i=1;i<=cont;i++) cout<<sum[i]<<endl;
    return 0;
}
