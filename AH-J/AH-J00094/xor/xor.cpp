#include<bits/stdc++.h>
using namespace std;
long long n,x,a[1000005];
long long maxx=0,sum=0;
bool vis[100000001];
void dfs(int r,int b){
    if(sum>maxx)maxx=sum;
    for(int i=r+1;i<=n+1;i++){
         b=b^a[i];
        if(b==x&&!vis[i]){
                vis[i]=1;
            sum++;
           //     cout<<i<<" "<<a[i+1]<<endl;
            dfs(i,0);
            sum--;

        }

           if(!vis[i]){
            vis[i]=1;
            dfs(i,b);
            vis[i]=0;
           }
    }
    return ;
}
int main(){
   freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(vis,0,sizeof(vis));
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=-1;
    dfs(0,0);
    cout<<maxx;
    return 0;
}
