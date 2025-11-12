#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,k,c[501][501];int a[5001];
void dfs(int x,int s,int z,int zd){
    if(x>n||z+n-x+1<3) return;
    if(x<=n){
        if(z>=2&&s+a[x]>max(zd,a[x])*2)k=(k+1)%mod;
        dfs(x+1,s+a[x],z+1,max(zd,a[x]));
        dfs(x+1,s,z,zd);
    }
}
long long C(int n,int m){
    if(!c[n][m]) return c[n][m];
    if(n==m)return 1;
    if(n==1) return m;
    return c[n][m]=(C(n-1,m-1)+C(n,m-1))%mod;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20){dfs(1,0,0,0);cout<<k<<endl;return 0;}
    for(int i=3;i<=n-1;i++){
        k=(k+C(i,n-1))%mod;
    }
    cout<<k<<endl;
    return 0;
    }
