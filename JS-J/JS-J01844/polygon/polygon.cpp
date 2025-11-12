#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int x[5005],ans,n,mx_of_all;

long long fast_pow(int a){
    if(a==0){
        return 1;
    }
    long long b=fast_pow(a/2);
    b*=b;
    if(a%2==1){
        b*=2;
    }
    return b%MOD;
}

void dfs(int i,int sum,int mx){
    if(i==n){
        if(sum!=0 && sum>2*mx){
            ans=(ans+1)%MOD;
        }
        return;
    }
    if(sum>mx_of_all*2){
        ans=(ans+fast_pow(n-i))%MOD;
        return;
    }
    dfs(i+1,sum,mx);
    dfs(i+1,sum+x[i],max(mx,x[i]));
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x[i];
        mx_of_all=max(mx_of_all,x[i]);
    }
    dfs(0,0,0);
    cout<<ans<<'\n';
    return 0;
}
