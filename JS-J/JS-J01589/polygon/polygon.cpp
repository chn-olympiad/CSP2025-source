#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
long long a[5010];
long long b[5010];
long long tmp[5010];
long long n;
long long ans=0;
bool cmp(long long a,long long b){
    return a>b;
}
long long c(long long m,long long n){
    long long ans=0;
    for(long long i=1,j=n;i<=m;i++,j--){
        ans=ans*j/i;
    }
    return ans;
}
long long dfs(long long num,long long st,long long x){
    tmp[st]=a[x];
    if(st==num){
        long long sum=0;
        for(long long i=1;i<=num;i++){
            sum+=tmp[i];
        }if(sum>tmp[1]*2)return 1;
        else return 0;
    }
    long long an1=0;
    for(long long i=x+st;i<=n-num+st+1;i++){
        an1+=dfs(num,st+1,i);
    }
    return an1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool f1=1;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f1=0;
        b[i]=b[i-1]+a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(f1){
        for(long long i=3;i<=n;i++){
            ans=(ans+c(i,n))%M;
        }
        cout<<ans;return 0;
    }
    if(n<=3){
        if(n==1||n==2)cout<<0;
        if(n==3){
            if(a[1]>a[2]+a[3])cout<<1;
            else cout<<0;
        }
        return 0;
    }
    for(long long i=3;i<=n;i++){
        ans=(ans+dfs(i,0,0))%M;
    }
    cout<<ans;
    return 0;
}
