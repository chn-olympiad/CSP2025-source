#include<bits/stdc++.h>
using namespace std;
long long T,n,a[5],cza[100005],aga[100005],agb[100005],agc[100005],cnta,cntb,cntc,ans,czb[100005],czc[100005];
pair<long long,long long>qwq[7];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
         cnta=0;cntb=0;cntc=0;ans=0;  //init
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[1]>>a[2]>>a[3];
            qwq[1].first=a[1];qwq[1].second=1;
            qwq[2].first=a[2];qwq[2].second=2;
            qwq[3].first=a[3];qwq[3].second=3;
            sort(qwq+1,qwq+4);
            ans+=qwq[3].first;
            if(qwq[3].second==1){
                cnta++;
                aga[cnta]=i;cza[cnta]=qwq[3].first-qwq[2].first;
            }
            if(qwq[3].second==2){
                cntb++;
                agb[cntb]=i;czb[cntb]=qwq[3].first-qwq[2].first;
            }
            if(qwq[3].second==3){
                cntc++;
                agc[cntc]=i;czc[cntc]=qwq[3].first-qwq[2].first;
            }}
            if(cnta>(n/2)){
                sort(cza+1,cza+1+cnta);
                for(int i=1;i<=cnta-(n/2);i++){
                    ans-=cza[i];
                }
            }
            if(cntb>(n/2)){
                sort(czb+1,czb+1+cntb);
                for(int i=1;i<=cntb-(n/2);i++){
                    ans-=czb[i];
                }
            }
            if(cntc>(n/2)){
                sort(czc+1,czc+1+cntc);
                for(int i=1;i<=cntc-(n/2);i++){
                    ans-=czc[i];
                }
            }
            cout<<ans<<endl;




    }
    return 0;
}
