#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
struct node{
    int x,y;
};
int dfs(int x,int sum){
    if(x>n)return 0;
    int ans=0;
    if(sum>a[x]*2)ans++;
    for(int i=x+1;i^n+1;i++){
        ans=(ans%mod+dfs(i,sum+a[i])%mod)%mod;
    }
    return ans%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<dfs(0,0)%mod;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
