#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005][3],csa[100005],csb[100005],csc[100005];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;int ans=0;csa[0]=csb[0]=csc[0]=0;
        for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
        for(int i=1;i<=n;i++){
            int mx=max({a[i][0],a[i][1],a[i][2]}),mx2;
            if(mx==a[i][0])mx2=max(a[i][1],a[i][2]),csa[++csa[0]]=mx-mx2,ans+=mx;
            else if(mx==a[i][1])mx2=max(a[i][0],a[i][2]),csb[++csb[0]]=mx-mx2,ans+=mx;
            else mx2=max(a[i][1],a[i][0]),csc[++csc[0]]=mx-mx2,ans+=mx;
        }
        if(csa[0]>0)sort(csa+1,csa+csa[0]+1);
        if(csb[0]>0)sort(csb+1,csb+csb[0]+1);
        if(csc[0]>0)sort(csc+1,csc+csc[0]+1);
        if(csa[0]>n/2){
            int df=csa[0]-n/2;
            for(int i=1;i<=df;i++)ans-=csa[i];
        }
        else if(csb[0]>n/2){
            int df=csb[0]-n/2;
            for(int i=1;i<=df;i++)ans-=csb[i];
        }
        else if(csc[0]>n/2){
            int df=csc[0]-n/2;
            for(int i=1;i<=df;i++)ans-=csc[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}