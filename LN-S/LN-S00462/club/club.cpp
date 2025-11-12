#include <bits/stdc++.h>
using namespace std;
struct sat{
    int t[4],fi,se,val,id;
}s[100005];
bool cmp(sat x,sat y){return x.val>y.val;}
int cnt[4];
void Solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&s[i].t[1],&s[i].t[2],&s[i].t[3]);
        if(s[i].t[1]>=s[i].t[2]){
            if(s[i].t[1]>=s[i].t[3]){
                if(s[i].t[2]>=s[i].t[3])s[i].fi=1,s[i].se=2;
                else s[i].fi=1,s[i].se=3;
            }
            else s[i].fi=3,s[i].se=1;
        }else{
            if(s[i].t[2]>=s[i].t[3]){
                if(s[i].t[1]>=s[i].t[3])s[i].fi=2,s[i].se=1;
                else s[i].fi=2,s[i].se=3;
            }
            else s[i].fi=3,s[i].se=2;
        }
        s[i].val=s[i].t[s[i].fi]-s[i].t[s[i].se];
        s[i].id=i;
    }
    sort(s+1,s+n+1,cmp);
    memset(cnt,0,sizeof cnt);
    long long ans=0;
    for(int i=1;i<=n;i++){
        int v=s[i].fi,u=s[i].se;
        if(cnt[v]<n/2)cnt[v]++,ans+=s[i].t[v];
        else cnt[u]++,ans+=s[i].t[u];
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
int T;scanf("%d",&T);while(T--)Solve();}