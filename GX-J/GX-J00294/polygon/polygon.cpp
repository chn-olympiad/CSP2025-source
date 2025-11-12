#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,df[5005];
bool z;
void dfs(int x,int p,int r){
    if(r==p+1){
        int s=0;
        for(int i=1;i<r;i++){
            s+=df[i];
        }
        if(s>df[r-1]*2){
            sum++;
            sum%=998244353;
        }
        return;
    }
    for(int i=x;i<=n;i++){
        df[r]=a[i];
        dfs(i+1,p,r+1);
    }
}
long long jie(int x){
    long long s=1;
    for(int i=2;i<=x;i++){
        s*=i;
        s%=998244353;
    }
    return s;
}
long long C(int m,int n){
    return jie(n)/(jie(m)*jie(n-m));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) z=1;
    }
    if(!z){
        for(int i=3;i<=n;i++){
            sum+=C(i,n)%998244353;
        }
        cout<<sum%998244353;
        return 0;
    }
    sort(a,a+n);
    for(int i=3;i<=n;i++){
        dfs(1,i,1);
    }
    cout<<sum%998244353;
    return 0;
}
