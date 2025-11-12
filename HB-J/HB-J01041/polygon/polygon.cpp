#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long MOD=998244353;
int a[5005];
long long n,ans=0,q[5005];
void dfs(int d,int maxn,int sum,int m){
    if(n-d+m<2)return;
    if(sum+q[d]<=2*maxn)return;
    if(d>n){
        if(sum>2*maxn&&m>=3)ans++;
        return;
    }
    dfs(d+1,maxn,sum,m);
    dfs(d+1,max(maxn,a[d]),sum+a[d],m+1);
    return;
}
long long ksm(int p){
    long long base=2,sum=1;
    while(p){
        if(p&1)sum=(sum*base%MOD);
        base=(base*base)%MOD;
        p>>=1;
    }
    return sum;
}
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    bool flag=true;
    for(int i=1;i<=n;i++){cin>>a[i];if(a[i]!=1)flag=false;}
    sort(a+1,a+n+1,cmp);
    for(int i=n;i>=1;i--)q[i]=q[i+1]+a[i];
    if(flag)ans=((ksm(n)-n-n*(n-1)/2-1)%MOD+MOD)%MOD;
    else dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
