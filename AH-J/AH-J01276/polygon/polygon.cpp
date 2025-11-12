#include<bits/stdc++.h>
#define int long long
using namespace std;
bool f=1;
int n,a[5005],cnt,mod=998244353;
void dfs(int step,int sum,int c,int maxn){
    if(step==n+1){
        if(c>=3&&sum>maxn*2){
            cnt=(cnt+1)%mod;
        }
        return ;
    }
    dfs(step+1,sum,c,maxn);
    dfs(step+1,sum+a[step],c+1,max(maxn,a[step]));
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f=0;
    }
    if(f==1){
        for(int i=3;i<=n;i++){
            int zxq=n,s1=1,s2=1;
            for(int j=1;j<=i;j++){
                s1=(s1*zxq)%mod;
                zxq--;
            }
            for(int j=1;j<=i;j++){
                s2=(s2*j)%mod;
            }
            cnt=(cnt+(s1/s2)%mod)%mod;
        }
    }else{
        dfs(1,0,0,-1);
    }
    cout<<cnt%mod;
    return 0;
}
