#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool vis[100005];
long long cnt;
int n;
bool flag=1;
void DFS(int k,int mx,int sum,int p){
    if(k==n+1){
        if(sum>2*mx&&p>=3) cnt++,cnt%=998244353;
        return;
    }
    vis[k]=0;
    DFS(k+1,mx,sum,p);
    vis[k]=1;
    mx=max(mx,a[k]);
    sum+=a[k];
    DFS(k+1,mx,sum,p+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=0;
    }
    DFS(1,INT_MIN,0,0);
    cout<<cnt;
    return 0;
}
