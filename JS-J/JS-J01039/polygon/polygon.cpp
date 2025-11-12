#include <bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010],maxn,sum,tmp;
void dfs(int num,int ans,int est,int wood){
    if(b[wood]>a[wood]){
        return;
    }
    tmp=tmp*(a[wood]-b[wood]+1);
    if(num>=3){
        sum+=tmp;
        sum%=998244353;
    }
    est=max(est,wood);
    for(int i=1;i<=maxn;i++){
        if((ans+i)>(max(est,i)*2)){
            b[i]++;
            dfs(num+1,ans+i,est,i);
            b[i]--;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int p;
        cin>>p;
        a[p]++;
    }
    for(int i=5000;i>=1;i--){
        if(a[i]){
            maxn=i;
            break;
        }
    }
    for(int i=1;i<=maxn;i++){
        if(a[i]){
            tmp=0;
            b[i]++;
            dfs(1,i,i,i);
            b[i]--;
        }
    }
    cout<<sum%998244353;
    return 0;
}
