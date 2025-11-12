#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
const int mod=998244353;
ll a[N];
ll maxn=0;
ll y[N][N];
void init(int n){
    y[0][0]=1;
    y[1][0]=y[1][1]=1;
    for(int i=2; i<=n; i++){
        y[i][0]=y[i][i]=1;
        for(int j=1; j<i; j++){
            y[i][j]=y[i-1][j-1]+y[i-1][j];
        }
    }
}
ll cnt=0;
void dfs(int x,int sum,int maxn,int p){
    if(x>p) return ;
    if(sum>maxn){
        int t=p-x;
        for(int i=0; i<=t; i++) cnt+=y[t][i],cnt%=mod;
        return ;
    }
    dfs(x+1,sum+a[x],maxn,p);
    dfs(x+1,sum,maxn,p);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    init(n+1);
    for(int i=1; i<=n; i++) cin>>a[i],maxn=max(maxn,a[i]);
    if(maxn==1){
        ll ans=0;
        for(int i=3; i<=n; i++) ans=(ans+y[n][i])%mod;
        cout<<ans;
    }
    else if(n<=20){
        sort(a+1,a+1+n);
        for(int i=3; i<=n; i++){
            dfs(1,0,a[i],i);
        }
        cout<<cnt;
    }
    else{
        sort(a+1,a+1+n);
        ll p;//the last
        ll ans=0;
        for(int i=3; i<=n; i++){
            if(i==3||a[i]!=a[i-1]){
                cnt=0;
                dfs(1,0,a[i],i);
                p=cnt;
                ans=(ans+p)%mod;
            }else{
                for(int j=1; j<=i-2; j++) p=p+y[i-2][j];
                ans=(ans+p)%mod;
            }
        }
        cout<<ans;
    }
    return 0;
}
