#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0;
int k[5005];
bool v[5005];
void dfs(int x,int sum,long long maxn,int l){
    if(x>=3){
        if(sum>maxn*2){
            ans++;
            ans%=998244353;
        }
    }
    if(x>n)
        return ;
    for(int i=l;i<=n;i++){
        if(!v[i]){
            v[i]=1;
            k[x+1]=a[i];
            dfs(x+1,sum+a[i],max(maxn,a[i]),i+1);
            v[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(0,0,0,1);
    cout<<ans;
}
