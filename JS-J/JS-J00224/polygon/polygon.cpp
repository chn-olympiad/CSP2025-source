#include<bits/stdc++.h>
using namespace std;
int len;
int ans=0;
int n;
int a[5005];
void dfs(int dep,int Max,int sum,int cnt,bool f){
     if(f){
        if((cnt>=3)&&(2*Max<sum)){
           ans++;
           ans%=998244353;
        }
     }
     if(dep==n+1){
        return;
     }
     dfs(dep+1,a[dep],sum+a[dep],cnt+1,true);
     dfs(dep+1,Max,sum,cnt,false);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=0;
        }
    }
    sort(a+1,a+n+1);
    if(f==0){
        dfs(1,0,0,0,true);
    }else{
        int j=2;
        for(int i=3;i<=n;i++){
            j*=i;
            ans+=j;
            ans%=998244353;
        }
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
