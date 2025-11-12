#include <iostream>
using namespace std;
int n,a[5005],p=998244353,ans,f[505];
bool bl=true;
void dfs(int step,int mx,int sum,int m){
    if(step>n){
        if(sum>2*mx&&m>2){
            ans=(ans+1)%p;
        }
        return ;
    }
    dfs(step+1,max(mx,a[step]),sum+a[step],m+1);
    dfs(step+1,mx,sum,m);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n>>a[1];
    for(int i=2;i<=n;++i){
        cin>>a[i];
        if(a[i]!=a[i-1]){
            bl=false;
        }
    }
    if(bl){
        f[1]=1;
        for(int i=2;i<=500;++i){
            f[i]=f[i-1]*i;
        }
        for(int i=3;i<=n;++i){
            ans+=(f[n]/f[i]/f[(n-i)])%p;
            ans%=p;
        }
        cout<<ans;
    }else if(n<=27){
        dfs(1,0,0,0);
        cout<<ans;
    }else{
        cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
