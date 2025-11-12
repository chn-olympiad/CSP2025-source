#include<bits/stdc++.h>
using namespace std;
long long n;
long long sum=0;
long long depn;
long long a[10000];
void dfs(int start,long long sumn,long long maxn,long long dep){
     if(dep>depn){
        if(sumn>maxn*2){
           sum=(sum+1)%999244353;
        }
        return ;
     }
     for(int i=start;i<=n;i++){
         dfs(i+1,sumn+a[i],max(maxn,a[i]),dep+1);
     }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for( depn=3;depn<=n;depn++){
        dfs(1,0,-1,1);
    }
    cout<<sum;
    return 0;
}
