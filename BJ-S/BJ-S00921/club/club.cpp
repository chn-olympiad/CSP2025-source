#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ll long long

const ll N=1e5+10;
ll n,a[N][10],c[N],dp[210][210][210],ans=0;

void dfs(ll s,ll i,ll j,ll k){
    if(i<0 || j<0 || k<0) return ;
    if(s==n+1){
        if(!(i==0 && j==0 && k==0)) return ;
        ll sum=0;
        for(ll i=1;i<=n;i++) sum+=a[i][c[i]];
        ans=max(ans,sum);
        return ;
    }
    
    c[s]=1;
    dfs(s+1,i-1,j,k);
    c[s]=0;

    c[s]=2;
    dfs(s+1,i,j-1,k);
    c[s]=0;

    c[s]=3;
    dfs(s+1,i,j,k-1);
    c[s]=0;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        bool flag1=true,flag2=true;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=3;j++){
                cin>>a[i][j];
            }
            if(a[i][2]!=0) flag1=false;
            if(a[i][3]!=0) flag1=false,flag2=false;
        }

        if(n<=30){
            for(ll i=0;i<=n/2;i++){
                for(ll j=0;j<=min(n-i+1,n/2);j++){
                    for(ll k=0;k<=min(n-i-j+1,n/2);k++){
                        if(i+j+k==n){
                            dfs(1,i,j,k);
                        }
                    }
                }
            }
            cout<<ans<<endl;
            ans=0;
        }else{
            if(flag1){
                ll b[N];
                memset(b,0,sizeof(b));
                for(ll i=1;i<=n;i++) b[i]=a[i][1];
                sort(b+1,b+n+1);

                ll sum=0;
                for(ll i=n;i>=n-n/2+1;i--) sum+=b[i];
                cout<<sum<<endl;
            }else{
                for(ll i=1;i<=n;i++){
                    for(ll j=1;j<=n/2;j++){
                        for(ll k=1;k<=min(n-j+1,n/2);k++){
                            dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][1],dp[i-1][j][k-1]+a[i][2]);
                        }
                    }
                }
                cout<<dp[n][n/2][n/2]<<endl;
            }
        }
    }
    return 0;
}