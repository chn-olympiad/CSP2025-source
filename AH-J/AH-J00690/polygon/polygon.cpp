#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[1001*5],b,c,i;
int s[5005];
void dfs(int sum,int in,int mx,int ff){
    if(ff==n){
        return ;
    }
    if(sum>mx*2&&in>=3){
        ans++;
    }
    for(int i=ff+1;i<=n;i++){
        dfs(a[i]+sum,in+1,max(mx,a[i]),i);
    }
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n<=2){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(s[a[i]]==0)dfs(a[i],1,a[i],i);
        s[a[i]]=1;
    }
    printf("%d",ans+3);
    return 0;
}
