#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans,b[N];
struct Node{
    int x,y,z;
} e[N];
void dfs(int p,int a,int b,int c,int sum){
    if(p==n+1){
        ans=max(ans,sum);
        return;
    }
    if(a+1<=n/2)
        dfs(p+1,a+1,b,c,sum+e[p].x);
    if(b+1<=n/2)
        dfs(p+1,a,b+1,c,sum+e[p].y);
    if(c+1<=n/2)
        dfs(p+1,a,b,c+1,sum+e[p].z);
}
bool cmp1(Node x,Node y){
    return x.x>y.x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        bool flagA,flagB;
        flagA=flagB=true;
        for(int i=1;i<=n;i++)
            cin>>e[i].x>>e[i].y>>e[i].z;
        for(int i=1;i<=n;i++)
            if(e[i].y!=0||e[i].z!=0)
                flagA=false;
        for(int i=1;i<=n;i++)
            if(e[i].z!=0)
                flagB=false;
        if(n<=10){
            dfs(1,0,0,0,0);
            cout<<ans<<'\n';
        }
        else if(flagA){
            sort(e+1,e+n+1,cmp1);
            for(int i=1;i<=n/2;i++)
                ans+=e[i].x;
            cout<<ans<<'\n';
        }
        else if(flagB){
            sort(e+1,e+n+1,cmp1);
            for(int i=1;i<=n;i++)
                b[i]=e[i].y-e[i].x;
            sort(b+1,b+n+1,greater<int>());
            for(int i=1;i<=n;i++)
                ans+=e[i].x;
            for(int i=1;i<=n/2;i++)
                ans+=b[i];
            cout<<ans<<'\n';
        }
    }
    return 0;
}