
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,M=998244353;
int n,a[N],ans=0,l[N],s;
bool fg[N];
void dfs(int k,int cnt,int maxn,int sum,int now){
    if(cnt==k){
        if(sum>maxn*2){ans++;/*cout<<maxn<<" "<<sum<<endl;*/ans%=M;
            //for(int i=1;i<=k;i++){
             //   cout<<l[i]<<" ";
            //}
            //cout<<endl;
        }
        return ;
    }
    for(int i=now;i<=n;i++){
        if(!fg[i]){
            //cout<<a[i]<<" ";
            fg[i]=1;
            l[cnt]=a[i];
            dfs(k,cnt+1,max(maxn,a[i]),sum+a[i],i);
            fg[i]=0;
        }
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    bool fg=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)s++;
    }
    if(s!=n)fg=0;
    else fg=1;
    if(!fg){
        for(int i=3;i<=n;i++){
            dfs(i,0,0,0,1); //cout<<ans<<" ";
        }
        cout<<ans%M<<endl;
    }else {
        cout<<n-2<<endl;
    }
    return 0;
}
