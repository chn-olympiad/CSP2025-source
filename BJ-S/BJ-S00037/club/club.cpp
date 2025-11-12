#include <bits/stdc++.h>
using namespace std;
struct a{
    int a,b,c;
}a[100005];
int ans;
int n;
void dfs(int x,int as,int bs,int cs,int sum){
    if(as>n/2||bs>n/2||cs>n/2) return;
    if(x==n+1){
        ans=max(ans,sum);
        return;
    }
    if(x==n&&sum+a[x].a<=ans) ;
    else dfs(x+1,as+1,bs,cs,sum+a[x].a);
    if(x==n&&sum+a[x].b<=ans) ;
    else dfs(x+1,as,bs+1,cs,sum+a[x].b);
    if(x==n&&sum+a[x].c<=ans) ;
    else dfs(x+1,as,bs,cs+1,sum+a[x].c);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
        ans=-114514;
    }
    return 0;
}
