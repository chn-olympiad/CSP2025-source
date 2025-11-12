#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
int n;
struct node{
    ll a,b,c;
}arr[100005];
int g1[100005],g2[100005],g3[100005];
bool cmp(int x,int y){
    return max(arr[x].b-arr[x].a,arr[x].c-arr[x].a)>max(arr[y].b-arr[y].a,arr[y].c-arr[y].a);
}
ll dp[205][205][205];
void upd(ll &x,ll y){
    x=max(x,y);
}
void brute(){
    for(int i=0;i<=200;i++) for(int j=0;j<=200;j++) for(int k=0;k<=200;k++){
        dp[i][j][k]=-1e18;
    }
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n/2;j++){
            for(int k=0;k<=n/2;k++){
                if(j) upd(dp[i][j][k],dp[i-1][j-1][k]+arr[i].b);
                if(k) upd(dp[i][j][k],dp[i-1][j][k-1]+arr[i].c);
                upd(dp[i][j][k],dp[i-1][j][k]+arr[i].a);
            }
        }
    }
    ll ans=0;
        for(int j=0;j<=n/2;j++){
            for(int k=0;k<=n/2;k++){
                if((n-j-k)<=n/2){
                    upd(ans,dp[n][j][k]);
                }
            }
        }
    cout<<ans<<"\n";
}
void solve(){
    cin>>n;
    ll ans=0,cnt1=0,cnt2=0,cnt3=0,mx=n/2;
    for(int i=1;i<=n;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].c;
        if(arr[i].a>=arr[i].b&&arr[i].a>=arr[i].c){
            ans+=arr[i].a;
            g1[++cnt1]=i;
        }else if(arr[i].b>=arr[i].a&&arr[i].b>=arr[i].c){
            ans+=arr[i].b;
            g2[++cnt2]=i;
        }else{
            ans+=arr[i].c;
            g3[++cnt3]=i;
        }
    }
    // if(n<=200){
    //     brute();
    //     return;
    // }
    if(cnt1<=mx&&cnt2<=mx&&cnt3<=mx){
        cout<<ans<<"\n";
        return;
    }
    priority_queue<ll> Q1,Q2;
    if(cnt2>mx){
        for(int i=1;i<=n;i++) swap(arr[i].a,arr[i].b);
        for(int i=1;i<=max(cnt1,cnt2);i++) swap(g1[i],g2[i]);
        swap(cnt1,cnt2);
    }else if(cnt3>mx){
        for(int i=1;i<=n;i++) swap(arr[i].a,arr[i].c);
        for(int i=1;i<=max(cnt1,cnt3);i++) swap(g1[i],g3[i]);
        swap(cnt1,cnt3);
    }
    sort(g1+1,g1+1+cnt1,cmp);
    int rst=cnt1-mx;
    ll fans=-inf;
    for(int i=1;i<=n;i++){
        int p=g1[i];
        int db=arr[p].b-arr[p].a,dc=arr[p].c-arr[p].a;
        if(db>=dc&&cnt2<=mx){
            cnt2++;
            ans+=db;
            Q1.push(arr[p].c-arr[p].b);
        }else if(dc>=db&&cnt3<=mx){
            cnt3++;
            ans+=dc;
            Q2.push(arr[p].b-arr[p].c);
        }else if(cnt2>mx){
            ans+=Q1.top()+db;
            cnt3++;
        }else{
            ans+=Q2.top()+dc;
            cnt2++;
        }
        if(i>=rst) fans=max(fans,ans);
    }
    cout<<fans<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}