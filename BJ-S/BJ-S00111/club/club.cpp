#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,sz;
struct A{
    ll u,v,w;
}a[100005];
bool cmp(A eee,A ddd){
    return eee.u>ddd.u;
}
int dfs(int x,int cnt1,int cnt2,int cnt3){
    if(x==n+1)return 0;
    ll ans=0;
    if(cnt1+1<=sz){
        ans=max(dfs(x+1,cnt1+1,cnt2,cnt3)+a[x].u,ans);
    }
    if(cnt2+1<=sz){
        ans=max(dfs(x+1,cnt1,cnt2+1,cnt3)+a[x].v,ans);
    }
    if(cnt3+1<=sz){
        ans=max(dfs(x+1,cnt1,cnt2,cnt3+1)+a[x].w,ans);
    }
    return ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        sz=n/2;
        int flag=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].u>>a[i].v>>a[i].w;
            if(a[i].v!=a[i].w||a[i].v!=0){
                flag=1;
            }
        }
        if(flag==0){
            ll ans=0;
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=sz;i++)ans+=a[i].u;
            cout<<ans<<endl;
            continue;
        }
        cout<<dfs(1,0,0,0)<<endl;
        //m.clear();
    }
    return 0;
}
