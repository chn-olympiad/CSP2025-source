#include <iostream>
using namespace std;
int a[5005],f[5005],xmax[5005],n,ans=0,sum=0;
void dfs(int step){
    if (sum>2*xmax[step]){
        ans++;
        ans=ans%998244353;
    }
    for (int i=step+1;i<=n;i++){
        if(f[i]==0){
            f[i]=1;
            sum+=a[i];
            xmax[i] = max(xmax[step],a[i]);
            dfs(i);
            f[i]=0;
            sum-=a[i];
        }
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0);
    cout<<ans;
    return 0;
}
