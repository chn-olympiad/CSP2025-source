#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,n,a[MAXN][4],ans=0,book[4];
struct NODE{
    int a,b,c;
}s[MAXN];
void dfs(int x,int sum){
    if(x==n+1){
        if(book[1]<=n/2&&book[2]<=n/2&&book[3]<=n/2)
            ans=max(ans,sum);
        return;
    }
    book[1]++;
    dfs(x+1,sum+s[x].a);
    book[1]--;
    book[2]++;
    dfs(x+1,sum+s[x].b);
    book[2]--;
    book[3]++;
    dfs(x+1,sum+s[x].c);
    book[3]--;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        book[1]=book[2]=book[3]=0;
        ans=0;
        for(int i=1;i<=n;i++)
            cin>>s[i].a>>s[i].b>>s[i].c;
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
