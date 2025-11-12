#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][5];
long long ans;
int cnt[5];
int cost[100005];
int mxj[100005];
int cst[100005],cntcs;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                mxj[i]=1;
                if(a[i][2]<=a[i][3]){
                    cost[i]=a[i][1]-a[i][3];
                }else{
                    cost[i]=a[i][1]-a[i][2];
                }
            }else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                mxj[i]=2;
                if(a[i][1]<=a[i][3]){
                    cost[i]=a[i][2]-a[i][3];
                }else{
                    cost[i]=a[i][2]-a[i][1];
                }
            }else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
                mxj[i]=3;
                if(a[i][2]<=a[i][1]){
                    cost[i]=a[i][3]-a[i][1];
                }else{
                    cost[i]=a[i][3]-a[i][2];
                }
            }
            ans+=a[i][mxj[i]];
            cnt[mxj[i]]++;
        }
        int mx=0;
        if(cnt[1]>=cnt[2]&&cnt[1]>=cnt[3])mx=1;
        if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[3])mx=2;
        if(cnt[3]>=cnt[2]&&cnt[3]>=cnt[1])mx=3;
//        cout<<ans<<endl;
        if(cnt[mx]<=n/2){
            cout<<ans<<endl;
            continue;
        }
        int k=cnt[mx]-(n/2);
        cntcs=0;
        for(int i=1;i<=n;i++){
            if(mxj[i]==mx)cst[++cntcs]=cost[i];
        }
        sort(cst+1,cst+1+cntcs);
        for(int i=1;i<=k;i++){
            ans-=cst[i];
//            cout<<cst[i]<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
