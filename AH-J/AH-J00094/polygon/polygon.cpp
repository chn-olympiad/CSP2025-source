#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],sum=0;
bool vis[100000001];
void dfs(int k,int m,int maxx,int maxx2){
    if(k>n)return ;
    if(m>2*maxx&&k>=3){
            sum++;

       // for(int i=1;i<=n;i++){
       //     cout<<vis[i]<<" ";
       // }
        //cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            maxx2=maxx;
            if(a[i]>maxx)maxx=a[i];
            m=m+a[i];
            dfs(k+1,m,maxx,maxx2);
            maxx=maxx2;
            m=m-a[i];
            vis[i]=0;
        }
    }
    return ;
}
int main(){
   freopen("polypon.in","r",stdin);
freopen("plygon.out","w",stdout);
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<sum;
    return 0;
}
