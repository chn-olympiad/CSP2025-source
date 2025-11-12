#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,s;
int a[5010];
void dfs(ll x,int y,int z,int u,int X){
    if(x>y*2 && u>=3 && X==1){
        s++;
        s%=998244353;
    }
    if(z==n){
        return ;
    }
    if(a[z]<=y){
        dfs(x+a[z],y,z+1,u+1,1);
    }
    if(a[z]>y){
        dfs(x+a[z],a[z],z+1,u+1,1);
    }
    dfs(x,y,z+1,u,0);

    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,-1,0,0,0);//dfs(x,y,u) x=sum y=max u=di ji ge ?(yes or no na);
    cout<<s;
    return 0;
}
