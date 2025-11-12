#include<bits/stdc++.h>
using namespace std;

int T,n;
int cnt[4];
int cse[4][100010];
struct sati{
    int d=0,id=0;
};
bool cmps(sati x,sati y){
    return x.d>y.d;
}
struct node{
    sati d[5];
}d[100010],D[100010];
bool cmp(int x,int y){
    return (d[x].d[1].d-d[x].d[2].d)<(d[y].d[1].d-d[y].d[2].d);
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        memset(cse,0,sizeof(cse));
        memset(d,0,sizeof(d));
        memset(D,0,sizeof(D));
        cin>>n;
        int upb=n/2;
        for(int i=1;i<=n;i++){
            cin>>d[i].d[1].d>>d[i].d[2].d>>d[i].d[3].d;
            D[i]=d[i];
            d[i].d[1].id=1;
            d[i].d[2].id=2;
            d[i].d[3].id=3;
            sort(d[i].d+1,d[i].d+4,cmps);
            cse[d[i].d[1].id][++cnt[d[i].d[1].id]]=i;
        }
        if(cnt[1]>upb){
            sort(cse[1]+1,cse[1]+cnt[1]+1,cmp);
            for(int i=1;i<=cnt[1]-upb;i++){
                cse[d[cse[1][i]].d[2].id][++cnt[d[cse[1][i]].d[2].id]]=cse[1][i];
                cse[1][i]=0;
            }
        }
        if(cnt[2]>upb){
            sort(cse[2]+1,cse[2]+cnt[2]+1,cmp);
            for(int i=1;i<=cnt[2]-upb;i++){
                cse[d[cse[2][i]].d[2].id][++cnt[d[cse[2][i]].d[2].id]]=cse[2][i];
                cse[2][i]=0;
            }
        }
        if(cnt[3]>upb){
            sort(cse[3]+1,cse[3]+cnt[3]+1,cmp);
            for(int i=1;i<=cnt[3]-upb;i++){
                cse[d[cse[3][i]].d[2].id][++cnt[d[cse[3][i]].d[2].id]]=cse[3][i];
                cse[3][i]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=cnt[i];j++){
                ans+=D[cse[i][j]].d[i].d;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
