#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
    int a,b,c;
}e[N];
int ans=0;
void dfs(int now,int sa,int sb,int sc,int l,int cnt){
    if(now==l+1){
        ans=max(ans,cnt);
        return ;
        //cout<<sa<<" "<<sb<<" "<<sc<<" "<<cnt<<endl;
    }
    if(sa+1<=(l/2))dfs(now+1,sa+1,sb,sc,l,cnt+e[now].a);
    if(sb+1<=(l/2))dfs(now+1,sa,sb+1,sc,l,cnt+e[now].b);
    if(sc+1<=(l/2))dfs(now+1,sa,sb,sc+1,l,cnt+e[now].c);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int o=1;o<=t;o++){
        int n;
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>e[i].a>>e[i].b>>e[i].c;
        }
        dfs(1,0,0,0,n,0);
        cout<<ans<<endl;
    }
    return 0;
}
