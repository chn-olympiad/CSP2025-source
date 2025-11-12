#include<bits/stdc++.h>
using namespace std;
int a[5010],cnt,n;
bool vis[5010];
void dfs(int x,int sum,int max1){
    if(x>=3&&sum>2*max1) cnt=(cnt+1)%998244353;
    if(x==n) return;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            dfs(x+1,sum+a[i],max(max1,a[i]));
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dfs(0,0,0);
    cout<<cnt/6;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
