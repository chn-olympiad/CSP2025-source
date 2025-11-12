#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e5+50;
int c1[MAXN],c2[MAXN],c3[MAXN];
int a[MAXN][4];
bool cmp1(int i,int j){
    return min(a[i][1]-a[i][2],a[i][1]-a[i][3])<min(a[j][1]-a[j][2],a[j][1]-a[j][3]);
}
bool cmp2(int i,int j){
    return min(a[i][2]-a[i][1],a[i][2]-a[i][3])<min(a[j][2]-a[j][1],a[j][2]-a[j][3]);
}
bool cmp3(int i,int j){
    return min(a[i][3]-a[i][2],a[i][3]-a[i][1])<min(a[j][3]-a[j][2],a[j][3]-a[j][1]);
}
void solve(){
    int n;
    cin>>n;
    int ans=0,cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])c1[++cnt1]=i;
        else if(a[i][2]>=a[i][3])c2[++cnt2]=i;
        else c3[++cnt3]=i;
        ans+=max({a[i][1],a[i][2],a[i][3]});
    }
    if(cnt1>n/2){
        sort(c1+1,c1+cnt1+1,cmp1);
        for(int i=1;i<=cnt1-n/2;i++)ans-=min(a[c1[i]][1]-a[c1[i]][2],a[c1[i]][1]-a[c1[i]][3]);
    }
    if(cnt2>n/2){
        sort(c2+1,c2+cnt2+1,cmp2);
        for(int i=1;i<=cnt2-n/2;i++)ans-=min(a[c2[i]][2]-a[c2[i]][1],a[c2[i]][2]-a[c2[i]][3]);
    }
    if(cnt3>n/2){
        sort(c3+1,c3+cnt3+1,cmp3);
        for(int i=1;i<=cnt3-n/2;i++)ans-=min(a[c3[i]][3]-a[c3[i]][2],a[c3[i]][3]-a[c3[i]][1]);
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
