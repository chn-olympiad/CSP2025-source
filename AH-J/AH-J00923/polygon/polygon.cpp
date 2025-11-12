#include<bits/stdc++.h>
using namespace std;
long long a[500001],ans[10011],vis[10011];
long long  n,ok1=1,sum,xxx;
long long inf=998244353;
bool check(long long xxxx){
    long long s=0,maxn=0;
    for(long long i=1;i<=xxxx;i++){
        s+=a[ans[i]];
        maxn=max(maxn,a[ans[i]]);
    }
    return s>maxn*2;
}
void dfs(long long c,long long dis){
    if(c>3){
        if(check(c-1))++sum;
        sum%=inf;
    }
    for(int i=dis;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            ans[c]=i;
            dfs(c+1,i+1);
            ans[c]=0;
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1)ok1=0;
    }
    if(n<=2){
        cout<<0;
    }
    else if(ok1){
        long long m=1;
        for(long long i=1;i<=n;i++){
            m=((m%inf)*2%inf);
        }
        int t=n*(n-1)/2;
        m=m+inf+inf+inf-1-(n%inf)-(t%inf);
        cout<<m%inf;
    }
    else{
        dfs(1,1);
        cout<<sum;
    }
    return 0;
}
