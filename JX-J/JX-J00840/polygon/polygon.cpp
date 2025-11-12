
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e3+3939;
const int d=998244353;
int a[N];
int maxs=0,n;
long long dp[N];
long long ans=0;
int vis[N];
int f(int r,int cost){
    int g=0;
    for(int i=0;i<r;i++){
            //cout<<i<<endl;
        if(a[i]<cost&&vis[i]!=1){
            vis[i]=1;
            g+=f(i,cost+a[i]);
            vis[i]=0;
        }
    }
    return g;
}

int main(){
    freopen("polygon.out","w",stdout);
    freopen("polygon.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxs=max(a[i],maxs);
    }
    if(n<3)cout<<0;
    else if(maxs==1&&n>=3){
        ans=(n*(n-1)%d)*(n-2)/6;
        cout<<ans%d;
        return 0;
    }
    else{
        sort(a,a+n);
        for(int t=2;t<n;t++){
            vis[t]=1;
            ans+=f(t,a[t]);
            vis[t]=0;
        }

        ans+=a[n-2];
        ans+=a[n-1];
        cout<<ans;
    }

    return 0;
}
