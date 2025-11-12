#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;

typedef long long ll;

const ll MOD=998244353;

ll n,k,ans;
ll ke[5005];
ll arr[5005];

void dfs(ll ind,ll maxn,ll sum,ll num){
    if(ind>n&&maxn*2<sum&&num>2){
        ans=(ans+1)%MOD;
        return ;
    }
    if(ind>n){
        return ;
    }
    dfs(ind+1,max(maxn,arr[ind+1]),sum+arr[ind+1],num+1);
    if(ind<n){
        dfs(ind+1,maxn,sum,num);
    }
}

void finit(ll n){
    ke[0]=1;
    for(int i=1;i<=n;i++){
        ke[i]=(ke[i-1]*2)%MOD;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        k=max(k,arr[i]);
    }
    if(k>1){
        dfs(0,0,0,0);
    }
    else{
        finit(n);
        ans=(ke[n]-1-n-n*(n-1)/2)%MOD;
    }
    cout<<ans%MOD<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
