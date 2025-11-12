#include<bits/stdc++.h>
using namespace std;
int n,ans,mx=0,flag=0;
int a[5005];
void dfs(int in,int shu,int sum,int bi){
    if(shu==bi){
        if(sum>a[in]*2){
            mx++;
        }
        return;
    }
    if(in>=n)return;
    for(int i=in+1;i<=n;i++){
        dfs(i,shu+1,sum+a[i],bi);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++){
        mx=0;
        dfs(0,0,0,i);
        ans+=mx;
    }
    cout<<ans;
    return 0;
}
