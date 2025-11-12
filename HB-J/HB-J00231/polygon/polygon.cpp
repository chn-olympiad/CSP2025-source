//score:24pts+12pts+28pts=64pts
#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,a[5010];
long long ans;
long long result;
void dfs(int line,int depth,int sum,int Max){
    if(depth==n+1){
        if(line>=3&&sum>2*Max) result=(result+1)%MOD;
        return;
    }
    dfs(line+1,depth+1,sum+a[depth],max(Max,a[depth]));
    dfs(line,depth+1,sum,Max);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=false;
    }
    if(flag){    //15,16,17,18,19,20 24pts
        ans=0;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                ans=(ans+j)%MOD;
            }
        }
        cout<<ans;
        return 0;
    }
    if(n==3){    //1,2,3 12pts
        int sum=a[1]+a[2]+a[3];
        int Max=(max(a[1],a[2]),a[3]);
        if(sum>2*Max) cout<<1;
        else cout<<0;
        return 0;
    }
    else{    //4,5,6,7,8,9,10 28pts
        dfs(0,1,0,0);
        cout<<result;
    }
    return 0;
}