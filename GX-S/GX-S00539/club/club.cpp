#include<bits/stdc++.h>
using namespace std;
int n,ans,T;
int fp[100005];
int myd[100005][5];
struct node{
    int a,b,c;
}m[100005];
void dfs(int pos,int a,int b,int c,int sum){
    if(pos>n+1) return ;
    if(a>n/2 or b>n/2 or c>n/2) return ;
    ans=max(ans,sum);
    dfs(pos+1,a+1,b,c,sum+myd[pos][1]);
    dfs(pos+1,a,b+1,c,sum+myd[pos][2]);
    dfs(pos+1,a,b,c+1,sum+myd[pos][3]);
}
bool cmp(node a,node b){
    return a.a>b.a;
}
void solve(){
    cin>>n;
    bool Apts=true,Bpts=false;
    for(int i=1;i<=n;i++){
        cin>>myd[i][1]>>myd[i][2]>>myd[i][3];
        if(myd[i][2]!=0 or myd[i][3]!=0)Apts=false;
        if(myd[i][3]!=0)Bpts=false;
        m[i].a=myd[i][1],m[i].b=myd[i][2],m[i].c=myd[i][3];
    }
    if(!Apts and !Bpts) dfs(1,0,0,0,0);
    else if(Apts){
        sort(m+1,m+1+n,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=m[i].a;
        }
    }
    else{
        sort(m+1,m+1+n,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=m[i].a;
        }
        for(int i=n/2+1;i<=n;i++){
            ans+=m[i].b;
        }
    }
    cout<<ans<<endl;
    ans=0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
