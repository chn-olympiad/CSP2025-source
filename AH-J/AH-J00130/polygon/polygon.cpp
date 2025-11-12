#include<iostream>
using namespace std;
long long n,a[5005],ans,b[5005],cnt;
void dfs(int t,long long sum){
    if(t>n){
        long long maxn=-0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=cnt;i++){
            maxn=max(maxn,b[i]);
        }
        if(maxn*2<sum&&cnt>0){
            ans++;
            ans%=998244353;
        }
        return ;
    }
    cnt++;
    b[cnt]=a[t];
    dfs(t+1,sum+a[t]);
    b[cnt]=0;
    cnt--;
    dfs(t+1,sum);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
