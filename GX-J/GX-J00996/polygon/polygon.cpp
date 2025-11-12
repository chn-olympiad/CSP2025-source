#include<bits/stdc++.h>
using namespace std;
int n,a[5010],num=0;
void dfs(int di,int sum,int maxn,int side){
    if(sum>maxn*2 && side>=3){
        num++;
        return;
    }
    if(di==n){
        return;
    }
    int maxf=max(maxn,a[di+1]);
    dfs(di+1,sum+a[di+1],maxf,side+1);
    dfs(di+1,sum,maxn,side);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,1,0);
    cout<<(num+1)%998244353;
}
