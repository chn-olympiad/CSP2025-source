#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n,a[100005][3];
int p[100005];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n;
        int s0=0,s1=0,s2=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int mx=max(a[i][0],max(a[i][1],a[i][2]));
            if(mx==a[i][0])s0++,p[i]=0;
            else if(mx==a[i][1])s1++,p[i]=1;
            else s2++,p[i]=2;
        }
        if(max(s0,max(s1,s2))<=n/2){
            int ans=0;
            for(int i=1;i<=n;i++){
                int mx=max(a[i][0],max(a[i][1],a[i][2]));
                ans+=mx;
            }
            cout<<ans<<'\n';
            continue;
        }
        else{
            int x=0;
            if(s0>n/2)x=0;
            else if(s1>n/2)x=1;
            else x=2;
            vector<int>v;
            int ans=0;
            for(int i=1;i<=n;i++){
                int mx=0,mmx=max(a[i][0],max(a[i][1],a[i][2]));
                ans+=mmx;
                if(x!=0)mx=max(mx,a[i][0]);
                if(x!=1)mx=max(mx,a[i][1]);
                if(x!=2)mx=max(mx,a[i][2]);
                if(p[i]==x)v.push_back(mmx-mx);
            }
            sort(v.begin(),v.end());
            int rr=max(s0,max(s1,s2));
            for(int i=0;i<rr-n/2;i++){
                ans-=v[i];
            }
            cout<<ans<<'\n';
            continue;
        }

    }
    return 0;
}
