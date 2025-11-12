#include<bits/stdc++.h>
using namespace std;
int a,b[100005],qzh=0,num=0,ans=0;
void dfs(int x){
    if(x==a+1){
        return ;
    }
    qzh+=b[x];
    num++;
    if(b[x]*2<qzh&&num>=3){
        ans=(ans+1)%998244353;
    }
    dfs(x+1);
    qzh-=b[x];
    num--;
    dfs(x+1);
}
long long c(int x,int y){
    long long sum=1;
    for(int i=1;i<=y;i++){
        sum*=x;
        x--;
    }
    return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    int maxn=-99;
    for(int i=1;i<=a;i++){
        cin>>b[i];
        maxn=max(maxn,b[i]);
    }
    sort(b+1,b+1+a);
    if(maxn==1){
        for(int i=a;i>=3;i--){
            ans=(ans+(c(a,i)/c(i,i))%998244353)%998244353;
        }
        cout<<ans;
    }
    else{

        dfs(1);
        cout<<ans;
    }
    return 0;
}
