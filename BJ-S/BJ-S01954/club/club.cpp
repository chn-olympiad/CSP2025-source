/*#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct stu{
    ll a,b,c,maxn,per;
    bool operator<(const stu&o)const{
        return  maxn>o.maxn;
    }
}pers[100001];
ll dp[100001][4],cnt[100001][4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.in","r",stdin);
    //freopen("main.out","w",stdout);
    ll t;
    cin>>t;
    for(ll xx=1;xx<=t;++xx){
        ll n;
        cin>>n;
        memset(pers,0,sizeof(pers));
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        for(ll i=1;i<=n;++i){
            cin>>pers[i].a>>pers[i].b>>pers[i].c;
            pers[i].maxn=max(pers[i].a,max(pers[i].b,pers[i].c));
            pers[i].per=i;
        }
        for(ll i=1;i<=n;++i){
                cout<<"1:"<<cnt[i-1][1]<<" ";
        cout<<"2:"<<cnt[i-1][2]<<" ";
        cout<<"3:"<<cnt[i-1][3]<<" ";
            if(cnt[i-1][1]*2<n){
                dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+pers[i].a;
                cnt[i][1]=cnt[i-1][1]+1;
            }
            if(cnt[i-1][2]*2<n){
                dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+pers[i].b;
                cnt[i][2]=cnt[i-1][2]+1;
            }
            if(cnt[i-1][3]*2<n){
                dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+pers[i].c;
                cnt[i][3]=cnt[i-1][3]+1;
            }
        }
        cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n";
    }
    return 0;
}
*/
/*
1
2
10 9 8
4 0 0
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[100001][4];
ll maxn=-1e9;
ll n;
void dfs(ll k,ll cnt1,ll cnt2,ll cnt3,ll sum){
    if(k>n){
        if(cnt1*2<=n&&cnt2*2<=n&&cnt3*2<=n)maxn=max(maxn,sum);
        return;
    }
    if(cnt1*2<n)dfs(k+1,cnt1+1,cnt2,cnt3,sum+a[k][1]);
    if(cnt2*2<n)dfs(k+1,cnt1,cnt2+1,cnt3,sum+a[k][2]);
    if(cnt3*2<n)dfs(k+1,cnt1,cnt2,cnt3+1,sum+a[k][3]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    cin>>t;
    for(ll i=1;i<=t;++i){
        cin>>n;
        for(ll j=1;j<=n;++j){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
        maxn=-1e9;
        dfs(1,0,0,0,0);
        cout<<maxn<<"\n";
    }
    return 0;
}
/*
1
2
10 9 8
4 0 0
*/