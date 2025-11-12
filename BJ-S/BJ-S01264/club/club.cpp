#include <bits/stdc++.h>
using namespace std;
int const N=2e5+3;
int n,a[N][3],p,cnt[3],ans,b[N];
vector <int> v;
inline void solve(){
    scanf("%d",&n),ans=p=cnt[0]=cnt[1]=cnt[2]=0,v.clear();
    for(int i=1;i<=n;++i){
        b[i]=0;
        for(int j=0;j<3;++j){
            scanf("%d",&a[i][j]);
            if(a[i][j]>a[i][b[i]]) b[i]=j;
        }
        ++cnt[b[i]],ans+=a[i][b[i]];
    }
    if(cnt[1]>cnt[p]) p=1;
    if(cnt[2]>cnt[p]) p=2;
    if(cnt[p]<=(n>>1)){
        printf("%d\n",ans);
        return ;
    }
    int tot=cnt[p]-(n>>1);
    for(int i=1;i<=n;++i){
        if(b[i]!=p) continue;
        int x=0;
        for(int j=0;j<3;++j) if(j!=p) x=max(x,a[i][j]);
        v.push_back(a[i][p]-x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<tot;++i) ans-=v[i];
    printf("%d\n",ans);
}
int main(){
    #ifndef wzh
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);
    #endif
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}