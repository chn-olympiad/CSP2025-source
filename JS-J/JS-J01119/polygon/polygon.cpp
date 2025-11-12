#include <bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n,l,r,mid;
long long a[5005];
long long pre[5005];
bool f=1;
long long ans;
void dfs(long long dep,long long sum,long long x){
    if(dep==x){
        if(sum>a[x]){
            ans++;
            ans%=Mod;
        }
        return;
    }
    if(sum+pre[x]-pre[dep-1]<=a[x]*2){
        return;
    }
    dfs(dep+1,sum+a[dep],x);
    if(sum+pre[x]-pre[dep]<=a[x]*2){
        return;
    }
    dfs(dep+1,sum,x);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1){
            f=0;
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(long long i=3;i<=n;i++){
        if(a[i]*2>=pre[i]){
            continue;
        }

        if(f){
            int q=pre[i]-3;
            long long sum=1;
            for(int i=1;i<=q;i++){
                sum*=2;
                sum%=Mod;
            }
            ans+=sum;
            ans%=Mod;
        }
        else

            dfs(1,0,i);
    }
    cout<<ans<<endl;
    return 0;
}
