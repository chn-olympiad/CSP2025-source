#include<bits/stdc++.h>
using namespace std;
int n,ans=0,cnt=-1,sum=0;
int a[5005],b[5005];
void dfs(int x,int y,int z){
    if(x>y){
        for(int k=1;k<=y;k++){
            sum+=b[k];
            cnt=max(b[k],cnt);
        }
        if(sum>2*cnt){
            ans=ans%998244353;
            ans++;
        }
        cnt=-1;
        sum=0;
        return ;
    }
    if(z>n)return ;
    for(int j=z;j<=n;j++){
        b[x]=a[j];
        dfs(x+1,y,j+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=3;i<=n;i++)
        dfs(1,i,1);
    cout<<ans;
    return 0;
}
