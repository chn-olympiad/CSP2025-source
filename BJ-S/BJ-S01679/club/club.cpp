//////////
#include <bits/stdc++.h>
using namespace std;
const int N = 114514;
int T,n,cnt[5],ans,t,vis[N],c1[N],c2[N];
bool flagg=true,flaggg=true;
struct nd{
    int v,p,id;
}aa[N*3];
struct nd2{
    int v,id;
}a[N][4];
bool cmp(nd a,nd b){
    return a.v>b.v;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;t=0;flagg=true;flaggg=true;
        memset(cnt,0,sizeof cnt);
        memset(vis,0,sizeof vis);
        memset(c1,0,sizeof c1);
        memset(c2,0,sizeof c2);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1].v>>a[i][2].v>>a[i][3].v;
            a[i][1].id=i,a[i][2].id=i,a[i][3].id=i;
            c1[i]=a[i][1].v,c2[i]=a[i][2].v;
            if(a[i][2].v!=0||a[i][3].v!=0) flagg=false;
            if(a[i][3].v!=0) flaggg=false;
            aa[++t]={a[i][1].v,i,1},aa[++t]={a[i][2].v,i,2},aa[++t]={a[i][3].v,i,3};
        }
        stable_sort(aa+1,aa+t+1,cmp);
        if(n==1){
            ans=max({a[1][1].v,a[1][2].v,a[1][3].v});
            return cout<<ans,0;
        }
        else if(n==2){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3&&i!=j;j++){
                    ans=max(ans,a[1][i].v+a[2][j].v);
                }
            }
            return cout<<ans,0;
        }
        else if(n==3){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3&&i!=j;j++){
                    for(int k=1;k<=3&&i!=k&&j!=k;k++){
                        ans=max(ans,a[1][i].v+a[2][j].v+a[3][k].v);
                    }
                }
            }
            return cout<<ans,0;
        }
        else if(n==4){
            int tt[5]={0,0,0,0,0};
            for(int i=1;i<=3;i++){
                tt[i]++;
                for(int j=1;j<=3;j++){
                    tt[j]++;
                    for(int k=1;k<=3;k++){
                        tt[k]++;
                        for(int l=1;l<=3;l++){
                            tt[l]++;
                            if(tt[1]<=n/2&&tt[2]<=n/2&&tt[3]<=n/2)
                                ans=max(ans,a[1][i].v+a[2][j].v+a[3][k].v+a[4][l].v);
                            tt[l]--;
                        }
                        tt[k]--;
                    }
                    tt[j]--;
                }
                tt[i]--;
            }
            return cout<<ans,0;
        }
        if(flagg){
            stable_sort(c1+1,c1+n+1);
            int cnt1=0;
            for(int i=n;i>=1&&cnt1<n/2;i--) ans+=c1[i],cnt1++;
            cout<<ans<<'\n';
            continue;
        }
        //if(flaggg){
        //
        //}
        //for(int i=1;i<=t;i++){
        //    if(cnt[aa[i].id]<n/2&&!vis[aa[i].p]){
        //        ans+=aa[i].v,cnt[aa[i].id]++,vis[aa[i].p]=1;
        //        printf("cnt[%d]:%d   p:%d   id:%d   v:%d\n",aa[i].id,cnt[aa[i].id],aa[i].p,a[i].id,aa[i].v);
        //    }
        //}
        cout<<ans<<'\n';
    }
    return 0;
}
//f[i][j][n-i-j]:c1->i   c2->j   c3->n-i-j      (max)
