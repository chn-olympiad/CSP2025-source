#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
    int a,b,c;
}t[N];
bool cmp(Node A,Node B){
    return A.a>B.a;
}
int n,T;
int vis[N][5];
int maxn;
void dfs(int x,int cnt1,int cnt2,int cnt3,int sum){
    if(x==n){
        maxn=max(maxn,sum);
        return ;
    }
    if(cnt1<n/2&&!vis[x+1][1]){
        vis[x+1][1]=1;
        dfs(x+1,cnt1+1,cnt2,cnt3,sum+t[x+1].a);
        vis[x+1][1]=0;
    }
    if(cnt2<n/2&&!vis[x+1][2]){
        vis[x+1][2]=1;
        dfs(x+1,cnt1,cnt2+1,cnt3,sum+t[x+1].b);
        vis[x+1][2]=0;
    }
    if(cnt3<n/2&&!vis[x+1][3]){
        vis[x+1][3]=1;
        dfs(x+1,cnt1,cnt2,cnt3+1,sum+t[x+1].c);
        vis[x+1][3]=0;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>t[i].a>>t[i].b>>t[i].c;
        }
        maxn=0;
        if(n>=100){
            sort(t,t+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                maxn+=t[i].a;
            }
            for(int i=n/2+1;i<=n;i++){
                maxn+=t[i].b;
            }
            cout<<maxn<<endl;
            continue;
        }
        memset(vis,0,sizeof(vis));
        dfs(0,0,0,0,0);
        cout<<maxn<<endl;
    }
    return 0;
}