#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll T;
bool vis[100005];
struct node{
    ll idx;
    ll grp;
    ll val;
};
struct node stu[300005];
ll read(){
    ll x=0;
    char c=getchar();
    while(!isdigit(c)){
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
bool cmp(struct node x,struct node y){
    return x.val>y.val;
}
ll dfs(ll n,ll idx,ll cnt1,ll cnt2,ll cnt3,ll val){
    if(idx==n+1){
        return val;
    }
    ll res=0;
    if(cnt1<n/2){
        res=max(res,dfs(n,idx+1,cnt1+1,cnt2,cnt3,val+stu[(idx-1)*3+1].val));
    }
    if(cnt2<n/2){
        res=max(res,dfs(n,idx+1,cnt1,cnt2+1,cnt3,val+stu[(idx-1)*3+2].val));
    }
    if(cnt3<n/2){
        res=max(res,dfs(n,idx+1,cnt1,cnt2,cnt3+1,val+stu[(idx-1)*3+3].val));
    }
    return res;
}
void solve(){
    ll n=0,ans=0;
    n=read();
    for(ll i=1;i<=n;i++){
        stu[(i-1)*3+1].idx=stu[(i-1)*3+2].idx=stu[(i-1)*3+3].idx=i;
        stu[(i-1)*3+1].grp=1;
        stu[(i-1)*3+2].grp=2;
        stu[(i-1)*3+3].grp=3;
        stu[(i-1)*3+1].val=read();
        stu[(i-1)*3+2].val=read();
        stu[(i-1)*3+3].val=read();
        vis[i]=false;
    }
    if(n<=200){
        cout<<dfs(n,1,0,0,0,0)<<endl;
        return;
    }
    sort(stu+1,stu+n*3+1,cmp);
    ll cnt[5]={0,0,0,0,0};
    for(ll i=1;i<=n*3;i++){
        if(vis[stu[i].idx]==false&&cnt[stu[i].grp]<n/2){
            vis[stu[i].idx]=true;
            cnt[stu[i].grp]++;
            ans+=stu[i].val;
        }
    }
    printf("%lld\n",ans);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--){
        solve();
    }
    return 0;
}