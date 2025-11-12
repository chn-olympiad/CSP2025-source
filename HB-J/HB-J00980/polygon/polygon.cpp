#include<bits/stdc++.h>

using namespace std;
int n,ans;
int a[5005];
void dfs(int x,int g,int maxn,int sum,int xb)
{
    if(g>x){
        if(sum>(2*maxn)){
            ans++;
            ans%=998244353;
        }
        return ;
    }
    for(int i=xb+1;i<=n;i++){
        dfs(x,g+1,max(maxn,a[i]),sum+a[i],i);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=3;i<=n;i++)
        dfs(i,1,0,0,0);
    cout<<ans;
    return 0;
}
/*
5
2 2 3 8 10
*/
