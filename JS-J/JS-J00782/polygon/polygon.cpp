#include<bits/stdc++.h>
using namespace std;
long long n,a[6000],ans,b[6000],vis[6000],r,tmp,sum,f;
void dfs(int pop){
    if(pop>r){
        sum=0;
        for(int i=1;i<pop;i++){
            sum+=b[i];
        }
        if(sum>a[tmp+1])ans++;
    }else{
        for(int i=1;i<=tmp;i++){
            if(vis[i]==0&&i>f){
                b[pop]=a[i];
                vis[i]=1;
                f=i;
                dfs(pop+1);
                f=0;
                vis[i]=0;
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
        return 0;
    }
    for(int i=3;i<=n;i++){
        for(int j=2;j<i;j++){
            r=j;
            tmp=i-1;
            dfs(1);
        }
    }
    cout<<ans%998244353;
    return 0;
}
