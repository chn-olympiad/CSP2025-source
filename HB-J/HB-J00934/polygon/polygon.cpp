#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010],h,shu=0;
void dfs(int n,int maxn,int i){
    if(i>h)return ;
    if(n>2*maxn){
        shu++;
    }

    dfs(n+a[i],max(maxn,a[i]),i+1);
    if(i!=5)dfs(n,maxn,i+1);

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>h;
    for(int i=1;i<=h;i++){
        cin>>a[i];
    }
    dfs(0,0,1);
    cout<<shu%mod;
    return 0;
}
