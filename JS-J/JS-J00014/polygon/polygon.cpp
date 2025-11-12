#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005,mod=998244353;
int n,a[N];
ll ans;
int C(int n,int m){
    if(m>n/2){
        m=n-m;
    }
    double sum=1;
    for(int i=1;i<=m;i++){
        sum*=(n-i+1);
        sum/=(m-i+1);
        //cerr<<"i: "<<i<<" j: "<<n-i+1<<" sum: "<<sum<<'\n';
    }
    //cerr<<"sum: "<<sum<<'\n';
    return sum;
}
int dfs(int x,int step,int sum,int mx){
    sum+=a[x],mx=max(mx,a[x]);
    //cerr<<"x: "<<x<<" step: "<<step<<" sum: "<<sum<<" mx: "<<mx<<'\n';
    if(step==1){
        //cerr<<":::::::::::::::::int\n";
        if(sum>mx*2){
            //cerr<<"::::::::::::::::sum: "<<sum<<" mx: "<<mx<<'\n';
        }
        return sum>mx*2;
    }
    int res=0;
    for(int i=x+1;i<=n-step+2;i++){
        //cerr<<"i: "<<i<<" up: "<<n-step+1<<'\n';
        res+=dfs(i,step-1,sum,mx);
    }
    return res;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    bool flag=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i),flag&=(a[i]==1);
    }
    if(flag){
        for(int i=3;i<=n;i++){
            (ans+=C(n,i))%=mod;
        }
    } else{
        for(int j=3;j<=n;j++){
            for(int i=1;i<=n;i++){
                if(n-i+1>=j){
                    //cerr<<"dfs: i: "<<i<<" j: "<<j<<'\n';
                    ans+=dfs(i,j,0,0);
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
