#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+7;
struct ccb{
    int ha,hb,hc;
    int fav,sev,f_s;
}peo[N];
int t,n,cnt[4],ans;
int cmp1(ccb a,ccb b){
    if(a.fav!=1)return 0;
    if(b.fav!=1)return 1;
    return a.f_s<b.f_s;
}
int cmp2(ccb a,ccb b){
    if(a.fav!=2)return 0;
    if(b.fav!=2)return 1;
    return a.f_s<b.f_s;
}
int cmp3(ccb a,ccb b){
    if(a.fav!=3)return 0;
    if(b.fav!=3)return 1;
    return a.f_s<b.f_s;
}
int fd(int i){
    int ma=max(max(peo[i].ha,peo[i].hb),peo[i].hc);
    if(ma==peo[i].ha){
        peo[i].fav=1;
        if(peo[i].hb>peo[i].hc){
            peo[i].sev=2;
            peo[i].f_s=peo[i].ha-peo[i].hb;
        }else{
            peo[i].sev=3;
            peo[i].f_s=peo[i].ha-peo[i].hc;
        }
    }else if(ma==peo[i].hb){
        peo[i].fav=2;
        if(peo[i].ha>peo[i].hc){
            peo[i].sev=1;
            peo[i].f_s=peo[i].hb-peo[i].ha;
        }else{
            peo[i].sev=3;
            peo[i].f_s=peo[i].hb-peo[i].hc;
        }
    }
    else{
        peo[i].fav=3;
        if(peo[i].ha>peo[i].hb){
            peo[i].sev=1;
            peo[i].f_s=peo[i].hc-peo[i].ha;
        }else{
            peo[i].sev=2;
            peo[i].f_s=peo[i].hc-peo[i].hb;
        }
    }
    //cout<<peo[i].fav<<endl;
    return ma;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cnt[1]=0;
        cnt[2]=0;
        cnt[3]=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>peo[i].ha>>peo[i].hb>>peo[i].hc;
            ans += fd(i);
            //cout<<peo[i].fav<<endl;
            cnt[peo[i].fav]++;
        }
        if(cnt[1]>=n/2){
                //cout<<"debug 1"<<endl;
            int c=cnt[1]- n/2;
            sort(peo+1,peo+n+1,cmp1);
            for(int i=1;i<=c;i++){
                //cout<<peo[i].f_s<<"---"<<i<<endl;
                ans-=peo[i].f_s;
            }
        }else if(cnt[2]>=n/2){
            int c=cnt[2]- n/2;
            sort(peo+1,peo+n+1,cmp2);
            for(int i=1;i<=c;i++){
                ans-=peo[i].f_s;
            }
        }else if(cnt[3]>=n/2){
            int c=cnt[3]- n/2;
            sort(peo+1,peo+n+1,cmp3);
            for(int i=1;i<=c;i++){
                ans-=peo[i].f_s;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
//36min AC T1
