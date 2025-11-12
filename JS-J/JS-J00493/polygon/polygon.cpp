#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5010;
const int md=998244353;
bool flag=true;
LL n,a[N],mx,ans,vis[N];
void dfs(int k,int tmp,LL s,int las){
    if(k==tmp+1){
        if(s>mx*2LL)ans=(ans+1)%md;
        return;
    }
    for(int i=las;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            LL last=mx;
            mx=max(mx,a[i]);
            dfs(k+1,tmp,s+a[i],i);
            mx=last;
            vis[i]=0;
        }
    }
}
LL A(LL m,LL n){
    LL sum=1;
    for(int i=m+1;i<=n;i++){
        sum=sum*i%md;
    }
    for(int i=1;i<=(n-m);i++){
        sum/=i;
    }
    return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flag=false;
        }
    }
    if(flag==true){
        for(int i=3;i<=n;i++){
           ans=(ans+A(i,n))%md;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        mx=0;
        memset(vis,0,sizeof(vis));
        dfs(1,i,0,1);
    }
    cout<<ans;
    return 0;
}
