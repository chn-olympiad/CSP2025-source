#include<bits/stdc++.h>
using namespace std;
long long n,a[5006],s=1,ans,jyh[5006][5006];
bool xz1;
int dfs(int bs,int zd,int sum,int sd,int xzd){
    if(jyh[bs][zd]!=0){
        return jyh[bs][zd];
    }
    if(sd==n){
        if(sum>zd){
            return 1;
        }
        else{
            return 0;
        }
    }
    for(int i=xzd-1;i>=1;i--){
        return jyh[bs][zd]=dfs(bs-1,zd,sum+a[i],sd+1,a[i]);
    }
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=s*2%998244353;
        if(a[i]!=1){
            xz1=1;
        }
    }
    if(xz1==0){
        cout<<(s-n-n*(n-1)/2-1)%998244353;
        return 0;
    }
    else if(n==3){
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    sort(a+1,a+n+1);
    for(int h=3;h<=n;h++){
        for(int i=1;i<=n;i++){
            jyh[h][i]=dfs(h-1,i,0,1,i);
            ans+=jyh[h][i];
        }
    }
    cout<<ans;
    return 0;
}
