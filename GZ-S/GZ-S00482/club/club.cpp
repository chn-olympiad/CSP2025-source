//GZ-S00482 贵州师范大学云岩实验中学 陈钧雷
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int n,memc[5],T;//memc: member count
long long ans;
pair<int,int> in[5];
pair<pair<int,int>,int> d[100005];
bool cmp1(pair<int,int> a,pair<int,int> b){return a.F<b.F;}
bool cmp2(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){return a.S>b.S;}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        for(int i=0;i<=2;i++) memc[i]=0;
        cin>>n;
        for(int i=0;i<n;i++){
            in[0].S=0;
            in[1].S=1;
            in[2].S=2;
            cin>>in[0].F>>in[1].F>>in[2].F;
            sort(in,in+3,cmp1);
            d[i]={in[2],in[2].F-in[1].F};
        }
        sort(d,d+n,cmp2);
        for(int i=0;i<n;i++){
            if(memc[d[i].F.S]>=n/2) ans+=d[i].F.F-d[i].S;
            else ans+=d[i].F.F,memc[d[i].F.S]++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}