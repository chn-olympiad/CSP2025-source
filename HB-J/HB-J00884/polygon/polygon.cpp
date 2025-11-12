#include<iostream>
#include<cstdio>
using namespace std;
const int N=5007,MOD=998244353;
long long a[N],n,x[N],ans,v[N];
bool check(int l){
    long long sum=0,maxn=-1;
    for(int i=1;i<l;i++){
        maxn=max(maxn,x[i]);
        sum+=x[i];
    }
    return sum>maxn*2;
}
void dfs(int step,int last){
    if(step>n+1)return;
    if(step>3&&check(step)){
        ans++;
        ans%=MOD;
    }
    for(int i=last+1;i<=n;i++){
        if(v[i])continue;
        x[step]=a[i];
        v[i]=1;
        dfs(step+1,i);
        v[i]=0;
    }
}
long long jc(int x){
    long long ans=1;
    for(int i=2;i<=x;i++)ans=ans*i%MOD;
    return ans;
}
int c(int n,int m){
    return jc(n)/jc(n-m)/jc(m);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f=0;
    }
    if(f){
        for(int i=3;i<=n;i++)ans=ans+c(n,i),ans%MOD;
        cout<<ans;
    }
    else{
        dfs(1,0);
        cout<<ans;
    }
    return 0;
}
