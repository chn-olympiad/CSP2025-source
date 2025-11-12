#include<bits/stdc++.h>
using namespace std;
int n;
long long k=0,mod=998244353;
int a[(int)5e3+10];
/*
*/
void dfs(long long s,long long m,int x,long long h){
    if(m>=3&&h>x*2){
        k++;
        k%=mod;
    }
    for(int i=s+1;i<=n;i++){
        dfs(i,m+1,max(x,a[i]),h+a[i]);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,0);
    cout<<k;
    return 0;
}
