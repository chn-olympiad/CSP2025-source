#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T,n;
struct Club{int d,id;};
struct Student{
    int diff,maxx,mxid,mx2id;
    Club b[4];
}a[100005];
bool cmp(Club a,Club b){
    return a.d>b.d;
}
bool cmp2(Student a,Student b){
    return a.diff>b.diff;
}
int p[4];
void solve(){
    p[1]=p[2]=p[3]=0;
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].b[1].d,&a[i].b[2].d,&a[i].b[3].d);
        a[i].b[1].id=1,a[i].b[2].id=2,a[i].b[3].id=3;
        sort(a[i].b+1,a[i].b+3+1,cmp);
        a[i].maxx=a[i].b[1].d,a[i].diff=a[i].b[1].d-a[i].b[2].d;
        a[i].mxid=a[i].b[1].id,a[i].mx2id=a[i].b[2].id;
    }
    sort(a+1,a+n+1,cmp2);
    for(int i=1;i<=n;i++){
        ans+=a[i].maxx;
        if(p[a[i].mxid]>=n/2) ans-=a[i].diff,++p[a[i].mx2id];
        if(p[a[i].mxid]<n/2) ++p[a[i].mxid];
    }
    printf("%lld\n",ans);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
//I Love CCF.
