#include <bits/stdc++.h>
using namespace std;
struct node{
    long long u,v,sum;
}x[2000005];
long long cnt=0,n,m,k,ans=0;
long long a[1005];
bool cmp(node x,node y){
    return x.sum<y.sum;
}
long long dfs(){
    a[x[1].u]=1;
    for(int i=1;i<=m;i++){
        if(a[x[i].v]==0){
            ans+=x[i].sum;
            a[x[i].v]=1;
            ++cnt;
        }
        if(cnt==n-1){
            return ans;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x[i].u>>x[i].v>>x[i].sum;
        x[i+m].u=x[i].v,x[i+m].v=x[i].u,x[i+m].sum=x[i].sum;

    }
    sort(x+1,x+1+2*m,cmp);
    long long t;
    for(long long i=0;i<=k;i++){
        cin>>t;
    }
    cout<<dfs();
    return 0;
}
