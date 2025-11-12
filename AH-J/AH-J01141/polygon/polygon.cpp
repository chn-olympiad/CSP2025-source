#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353;
int N;
int a[5010];
int cnm(int n,int m){
    if(m>n) return 0;
    if(m==n||n==1||m==0) return 1;
    if(m==1) return n;
    return cnm(n-1,m)+cnm(n-1,m-1);
}
int power(int d,int z){
    if(z==0){
        if(d) return 1;
        return 0;
    }
    int ans=1;
    while(z>1){
        if(z&1){
            ans*=d;
            ans%=M;
        }
        d*=d;
        d%=M;
        z/=2;
    }
    return (d%M)*(ans%M);
}
int ans;
void dfs(int step,int sum,int mx){
    if(step==N+1){
        if(sum>2*mx){
            ans++;
            ans%=M;
        }
        return;
    }
    dfs(step+1,sum,mx);
    dfs(step+1,sum+a[step],max(mx,a[step]));
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.in","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    bool f=1;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        if(a[i]!=1) f=0;
    }
    if(f){
        cout<<power(2,N)-1-N-cnm(N,2);
    }
    else{
        dfs(1,0,0);
        cout<<ans;
    }
    return 0;
}
