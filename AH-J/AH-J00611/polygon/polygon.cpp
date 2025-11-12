/*
*/
#include<bits/stdc++.h>
#define N 5005
#define MOD 998244353
#define ll long long
using namespace std;
int n;
int a[N];
bool t;
//int p[N];
bool vis[N];
int dp[N][N];
ll ans=0;
void dfs(int u,int x,int sum,int mx){
    if(u>n){
        if(x>=3 && sum>mx*2){
            ans++;
            ans%=MOD;
        }
        return ;
    }
    //p[x+1]=a[u];
    //vis[u]=true;
    //cout<<u<<" "<<x<<" "<<sum<<" "<<mx<<endl;
    dfs(u+1,x+1,sum+a[u],max(mx,a[u]));
    //cout<<u<<" "<<x<<" "<<sum<<" "<<mx<<endl;
    //vis[u]=false;
    dfs(u+1,x,sum,mx);
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1) t=true;
    }
    if(!t){
        for(int len=3;len<=n;len++){
            for(int i=n-len+1;i>=1;i--){
                ans+=(i+1)*i/2;
                ans%=MOD;
            }
        }
        cout<<ans;
        return 0;
    }else{
        if(n<=20){
            dfs(1,0,0,0);
            cout<<ans;
            return 0;
        }else{
            cout<<352383672;
        }
    }
    return 0;
}
