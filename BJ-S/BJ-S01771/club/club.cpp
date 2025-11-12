#include<bits/stdc++.h>
using namespace std;
const int MAXLEN=1e5+5;
int T,n,a[3][MAXLEN],cnt[3];
struct node{
    int ma,me,mi,id;
    bool operator < (const node &rhs) const{
        return (a[ma][id]-a[me][id])<(a[rhs.ma][rhs.id]-a[rhs.me][rhs.id]);
    }
}d[MAXLEN];

void solve(){
    memset(a,0,sizeof(a));
    memset(d,0,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        d[i].ma=-1;
        scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
        for(int j=0;j<=2;j++){
            if(d[i].ma==-1&&a[j][i]==max(a[0][i],max(a[1][i],a[2][i]))) d[i].ma=j;
            else if(a[j][i]==min(a[0][i],min(a[1][i],a[2][i]))) d[i].mi=j;
        }
        d[i].me=(d[i].ma^d[i].mi^3);
        d[i].id=i;
        //printf("%d %d %d\n",d[i].ma,d[i].me,d[i].mi);
    }
    sort(d+1,d+1+n);
    int ans=0;
    for(int i=n;i>=1;i--){
        //printf("%d %d %d %d %d %d\n",d[i].ma,a[d[i].ma][d[i].id],d[i].me,a[d[i].me][d[i].id],d[i].mi,a[d[i].mi][d[i].id]);
        if(cnt[d[i].ma]<(n>>1)){
            ans+=a[d[i].ma][d[i].id];
            cnt[d[i].ma]++;
        }else{
            ans+=a[d[i].me][d[i].id];
            cnt[d[i].me]++;
        }
    }
    printf("%d\n",ans);
}


signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}
