#include<bits/stdc++.h>
using namespace std;
long long a,b,c,n,m,x[50005],biao[5005],k1;
void dfs(int k,long long sum,int maxn){
    if(k==0){
        if(sum>x[maxn]*2) k1++;
        return ;
    }
    if(maxn==n){
        return ;
    }
    for(int i=maxn+1;i<=n;i++){
        sum+=x[i];
        dfs(k-1,sum,i);
        sum-=x[i];
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    sort(x+1,x+1+n);
    for(int i=3;i<=n;i++){
        dfs(i,0,0);
    }
    cout<<k1%998244353;
    return 0;
}
