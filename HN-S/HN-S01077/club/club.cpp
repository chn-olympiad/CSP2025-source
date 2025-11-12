#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct node{
    int a,b,c;
};
int n;
int cnt1=0,cnt2=0,cnt3=0,ans=0,l;
node a[100010];
int dp[100010];
void dfs(int x,int sum){
    if(x>n){
        ans=max(ans,sum);
        return;
    }
    if(cnt1+1<=l){
        cnt1++;
        dfs(x+1,sum+a[x].a);
        cnt1--;
    }if(cnt2+1<=l){
        cnt2++;
        dfs(x+1,sum+a[x].b);
        cnt2--;
    }if(cnt3+1<=l){
        cnt3++;
        dfs(x+1,sum+a[x].c);
        cnt3--;
    }
    dfs(x+1,sum);
}
void solve(){
    cin>>n;
    l=n/2;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
        dp[i]=0;
    }ans=0;dfs(1,0);
    cout<<ans<<endl;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
