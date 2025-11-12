#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,ans;
struct ab{
    int a,b,c;
}a[200005];
void dfs(int x,int cnt,int ca,int cb,int cc){
    ans=max(ans,cnt);
    if(x==n) return;
    if(ca+1<=n/2) dfs(x+1,cnt+a[x+1].a,ca+1,cb,cc);
    if(cb+1<=n/2) dfs(x+1,cnt+a[x+1].b,ca,cb+1,cc);
    if(cc+1<=n/2) dfs(x+1,cnt+a[x+1].c,ca,cb,cc+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        ans=0;
        dfs(0,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
