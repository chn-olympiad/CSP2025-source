#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005;
int n,a[N];
bool f=0;
int ans=0;

void dfs(int x,int sum,int mx,int step,bool flag){
    if(step>=3&&sum>mx*2&&flag){
        //cout<<sum<<" "<<mx<<" "<<step<<endl;
        ans++;
        ans%=mod;
    }
    if(x>n)return;
    dfs(x+1,sum,mx,step,0);
    dfs(x+1,sum+a[x],max(mx,a[x]),step+1,1);
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f=1;
    }
    if(!f){
        for(int i=3;i<=n;i++){
            long long cnt=1;
            for(int k=0;k<i;k++){
                cnt=(cnt*(n-k))%mod;
            }
            long long p=1;
            for(int j=1;j<=n-i;j++)p*=j;
            for(int j=1;j<=i;j++)p*=j;
            ans=(ans+cnt/p)%mod;
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0,0,0,0);
    cout<<ans;
    return 0;
}
