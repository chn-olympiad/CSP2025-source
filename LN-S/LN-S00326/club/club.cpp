#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[100001],b[100001],c[100001],f[100001];
ll vis[100001],cnt,ans;
void dfs(ll x,ll a1,ll b1,ll c1,ll p){
    if(a1>n/2||b1>n/2||c1>n/2){
        return;
    }
    if(x>n){
     //   cout<<cnt<<endl;
        cnt=max(cnt,p);
        return;
    }
    dfs(x+1,a1+1,b1,c1,p+a[x]);
    dfs(x+1,a1,b1+1,c1,p+b[x]);
    dfs(x+1,a1,b1,c1+1,p+c[x]);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    for(ll i=1;i<=t;i++){
        scanf("%lld",&n);
        cnt=0;
        b[1]=0;
        b[2]=0;
        b[3]=0;
        ans=0;
        if(n<=10){
            for(ll j=1;j<=n;j++){
                scanf("%lld%lld%lld",&a[j],&b[j],&c[j]);
            }
            cnt=0;
         //   cout<<"po:"<<endl;
            dfs(1,0,0,0,0);
        }else{
            cnt=0;
            for(ll j=1;j<=n;j++){
                scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
                ll u=max(a[1],max(a[2],a[3]));
                if(u==a[1]){
                    b[1]++;
                    c[j]=1;
                }else if(u==a[2]){
                    b[2]++;
                    c[j]=2;
                }else{
                    b[3]++;
                    c[j]=3;
                }
                sort(a+1,a+1+3);
                vis[j]=a[3]-a[2];
                cnt+=u;
            }
           // cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
            if(b[1]>n/2){
             //   cout<<1<<endl;
                ans=0;
                for(ll j=1;j<=n;j++){
                    if(c[j]==1){
                        ans++;
                        f[ans]=vis[j];
                    }
                }
                //cout<<cnt<<endl;
                sort(f+1,f+1+ans);
                for(ll j=1;j<=b[1]-n/2;j++){
                //    cout<<f[j]<<endl;
                    cnt-=f[j];
                }
            }else if(b[2]>n/2){
                ans=0;
                for(ll j=1;j<=n;j++){
                    if(c[j]==2){
                        ans++;
                        f[ans]=vis[j];
                    }
                }
                sort(f+1,f+1+ans);
                for(ll j=1;j<=b[2]-n/2;j++){
                    cnt-=f[j];
                }
            }else{
                ans=0;
                for(ll j=1;j<=n;j++){
                    if(c[j]==3){
                        ans++;
                        f[ans]=vis[j];
                    }
                }
                sort(f+1,f+1+ans);
                for(ll j=1;j<=b[3]-n/2;j++){
                    cnt-=f[j];
                }
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
