#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const long long mod=998244353;
int n;
int a[N];
long long ans;
bool f=1;

void dfs(int now,int sum,int maxa){
    if(now==n+1){
        if(sum>maxa*2){
            ans++;
        }
        return ;
    }
    dfs(now+1,sum,maxa);
    dfs(now+1,sum+a[now],max(maxa,a[now]));
    return ;
}

long long fpow(int x,int y){
    long long num=1,base=x;
    while(y!=0){
        if(y%2==1){
            num=num*base%mod;
        }
        base=base*base%mod;
        y/=2;
    }
    return num;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=0;
        }
    }
    if(f==1){
        ans=(fpow(2,n)-n*(n+1)/2%mod-1+mod)%mod;
    }else if(f==0 && n<=20){
        dfs(1,0,0);
    }else{
        ans=(fpow(2,n)-n*(n+1)/2%mod-1+mod)%mod;
    }
    cout<<ans;
    return 0;
}
