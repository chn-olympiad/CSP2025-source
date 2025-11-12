//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>
using namespace std;
struct node{
    int v,id;
};
node f1[100005];
node f2[100005];
node f3[100005];
bool k[100005];
int a[100005][3];
bool cmp(node x,node y){return x.v>y.v;}
void solve(){
    memset(k,0,sizeof(k));
    int n;cin>>n;
    int cnt1=0,cnt2=0,cnt3=0,tot=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        tot+=max(a[i][0],max(a[i][1],a[i][2]));
        if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]){
            f1[++cnt1].v=a[i][0]-max(a[i][1],a[i][2]);
            f1[cnt1].id=i;
        }
        else if(a[i][1]>=a[i][2]){
            f2[++cnt2].v=a[i][1]-max(a[i][0],a[i][2]);
            f2[cnt2].id=i;
        }
        else{
            f3[++cnt3].v=a[i][2]-max(a[i][0],a[i][1]);
            f3[cnt3].id=i;
        }
    }
    int ans=0;
    if(cnt1>n/2){
        sort(f1+1,f1+cnt1+1,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=a[f1[i].id][0];k[f1[i].id]=1;
        }
        for(int i=1;i<=n;i++){
            if(!k[i]){
                ans+=max(a[i][1],a[i][2]);
            }
        }
        cout<<ans<<endl;return;
    }
    if(cnt2>n/2){
        sort(f2+1,f2+cnt2+1,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=a[f2[i].id][1];k[f2[i].id]=1;
        }
        for(int i=1;i<=n;i++){
            if(!k[i]){
                ans+=max(a[i][0],a[i][2]);
            }
        }
        cout<<ans<<endl;return;
    }
    if(cnt3>n/2){
        sort(f3+1,f3+cnt3+1,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=a[f3[i].id][2];k[f3[i].id]=1;
        }
        for(int i=1;i<=n;i++){
            if(!k[i]){
                ans+=max(a[i][0],a[i][1]);
            }
        }
        cout<<ans<<endl;return;
    }
    cout<<tot<<endl;
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
