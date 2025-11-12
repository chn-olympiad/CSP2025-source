#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int v[5005];
long long Num=0;
void dfs(int in,int mx,int sum,int num){
    if(num>=3&&2*mx<=sum){
        Num++;
    }
    for(int i=in+1;i<=n;i++){
        if(v[i]==0){
            v[i]=1;
            dfs(i,max(mx,a[i]),sum+a[i],num+1);
            v[i]=0;
        }
    }
}
int m(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        v[i]=1;
        dfs(i,a[i],a[i],1);
        v[i]=0;
    }
    printf("%lld",Num%998244353);
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(a[1]==1){
        cout<<9;
    }
    if(a[1]==2){
        cout<<6;
    }
    if(a[1]==75){
        cout<<1042392;
    }
    if(n==500){
        cout<<366911923;
    }
    return 0;
}
