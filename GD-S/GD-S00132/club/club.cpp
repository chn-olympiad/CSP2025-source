#include<bits/stdc++.h>
#define FILE(str) freopen(str".in","r",stdin),freopen(str".out","w",stdout)
inline void read(int &x){
    x=0;int f(1);
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    x=x*f;
}
using vi=std::vector <int>;
using pii=std::pair <int,int>;
const int MAXN=1e5+5;
int n;
struct node{
    int val[3];
    int pos;
}a[MAXN];
int cnt[3];
inline void solve(){
    read(n);
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++) read(a[i].val[j]);
        for(int j=0;j<3;j++) if(a[i].val[j]>a[i].val[a[i].pos]) a[i].pos=j;
    }
    std::sort(a+1,a+n+1,[](node x,node y){return x.val[x.pos]>y.val[y.pos];});
    int ans(0);
    for(int i=1;i<=n;i++){
        ++cnt[a[i].pos],ans+=a[i].val[a[i].pos];
    }
    int lim=0;
    for(int i=0;i<3;i++) if(cnt[i]>cnt[lim]) lim=i;
    if(cnt[lim]<=n/2) return printf("%d\n",ans),void();
    std::priority_queue <int> q;
    for(int i=1;i<=n;i++) if(a[i].pos==lim){
        int maxn(0);
        for(int j=0;j<3;j++) if(lim!=j) maxn=std::max(maxn,a[i].val[j]);
        q.push(maxn-a[i].val[lim]);
    }
    while(cnt[lim]>n/2){
        ans+=q.top();
        q.pop();
        --cnt[lim];
    }
    printf("%d\n",ans);
}
signed main(){
    FILE("club");
    int T;read(T);
    while(T--) solve();
}
//已严肃完成不女装何以CSP大学习