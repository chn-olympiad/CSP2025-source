#include<iostream>
#include<algorithm>
#include<cstdio>
#define MOD 998244353
using namespace std;
int n,m;
int ans;
int a[5005];
//int dp[][];
bool f;
void dfs(int x,int m,int Max,int sum){
    if(x==n+1){
        if(m>=3&&Max*2<sum){
            ans++;
        }
        return ;
    }
    dfs(x+1,m+1,max(Max,a[x]),sum+a[x]);
    dfs(x+1,m,Max,sum);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","W",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=1;
        }
    }
    if(f!=1){
        for(int i=3;i<=n;i++){
            int suma=1,sumb=1;
            for(int j=n;j>n-i;j--){
                sumb*=(n-j+1)%MOD;
                sumb%=MOD;
                suma*=j%MOD;
                suma%=MOD;
                if(suma%sumb==0){
                    suma/=sumb;
                    sumb=1;
                }
            }
            //cout<<suma<<"\n";
            ans+=suma%MOD;
            ans%=MOD;
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
dp[i][j]:前i个元素中选出j个小木棍(必选第i个）能够拼成一个多边形的方案数%998244353
dp[i][j]=dp[i][j-1]
*/





