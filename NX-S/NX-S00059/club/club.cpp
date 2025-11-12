#include<bits/stdc++.h>
using namespace std;
#define int long long
int cd=0;
struct rate {
    int id,ra,rb,rc;
};
bool cmp(rate a,rate b) {
    if(cd==1)
        return a.ra>b.ra;
    if(cd==2)
        return a.rb>b.rb;
    if(cd==3)
        return a.rc>b.rc;
    else
        return a.id>b.id;
}
rate rt[100001],a[100001],b[100001],c[100001];
int where[100001];
void work() {
    int n;
    scanf("%lld",&n);
    int lim=n/2;
    int ca=0,cb=0,cc=0,ma=0,mb=0,mc=0;
    int na=0,nb=0,nc=0;
    memset(where,0,sizeof(where));
    for(int i=1;i<=n;i++) {
        int ra,rb,rc;
        scanf("%lld %lld %lld",&ra,&rb,&rc);
        rt[i]={i,ra,rb,rc};
        a[i]=b[i]=c[i]={i,ra,rb,rc};
    }
    cd=1;
    sort(a+1,a+n+1,cmp);
    for(int i=1;ma<lim&&i<=n;i++) {
        where[a[i].id]=1;
        ca+=a[i].ra;
        ma++,na++;
    }
    cd=2;
    sort(b+1,b+n+1,cmp);
    for(int i=1;mb<lim&&i<=n;i++) {
        if(where[b[i].id]==1) {
            if(rt[b[i].id].rb+a[ma+1].ra>rt[b[i].id].ra) {
                ca-=rt[b[i].id].ra,cb+=rt[b[i].id].rb,where[b[i].id]=2,mb++,nb++,ca+=a[++ma].ra,where[a[ma].id]=1; // get members from A
            }
        }
        else {
            where[b[i].id]=2,ca+=b[i].rb,mb++,nb++;
        }
    }
    cd=3;
    sort(c+1,c+n+1,cmp);
    for(int i=1;mc<lim&&i<=n;i++) { // get members from A and B
        if(where[c[i].id]==1) {
            if(rt[c[i].id].rc+a[ma+1].ra>rt[c[i].id].ra) {
                ca-=rt[c[i].id].ra,cc+=rt[c[i].id].rc,mc++,where[c[i].id]=3,na--,nc++;
            }
        }
        else {
            if(rt[c[i].id].rc+b[mb+1].rb>rt[c[i].id].rb) {
                cb-=rt[c[i].id].rb,cc+=rt[c[i].id].rc,mc++,where[c[i].id]=3,nb--,nc++;
            }
        }
    }
    int res=ca+cb+cc;
    printf("%lld\n",res);
    for(int i=1;i<=n;i++)
        printf("%lld ",where[i]);
    printf("\n");
}
signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int c;
    scanf("%lld",&c);
    while(c--) {
        work();
    }
    return 0;
}