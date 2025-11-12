#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans=0;
int a[5005];
void dfs(int x,int num,int maxn,int st){
    if(x==0){
        if(maxn*2<num){
            ans=(ans+1)%mod;
        }
        return ;
    }
    for(int i=st;i<=n;i++){
        if(a[i]!=-1){
            int t=a[i];
            a[i]=-1;
            dfs(x-1,num+t,max(maxn,t),i+1);
            a[i]=t;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0<<endl;
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        dfs(i,0,0,1);
    }
    cout<<ans<<endl;
    return 0;
}
