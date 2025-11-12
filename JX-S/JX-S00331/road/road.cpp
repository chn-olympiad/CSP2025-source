#include<bits/stdc++.h>
using namespace std;
struct node{
    int left;
    int right;
    int pay;
}road[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,m,k,u[100005],v[100005],w[100005],ans=0,dp[10005][10005],x;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>road[i].left>>road[i].right>>road[i].pay;
        x+=road[i].pay;
    }
    for(int i=1;i<=k;i++){
        cin>>u[i]>>v[i];
    }
    cout<<x<<endl;
    return 0;
}
