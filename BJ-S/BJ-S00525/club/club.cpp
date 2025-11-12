#include <bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
struct price{
    long long a,b,c;
} s[100005];
void dfs(int step,long long res,int c1,int c2,int c3){
    if(step>n){
        ans=max(ans,res);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(c1+1<=n/2){
            c1++,res+=s[step].a;
            dfs(step+1,res,c1,c2,c3);
            c1--,res-=s[step].a;
        }
        if(c2+1<=n/2){
            c2++,res+=s[step].b;
            dfs(step+1,res,c1,c2,c3);
            c2--,res-=s[step].b;
        }
        if(c3+1<=n/2){
            c3++,res+=s[step].c;
            dfs(step+1,res,c1,c2,c3);
            c3--,res-=s[step].c;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;++i){
           cin>>s[i].a>>s[i].b>>s[i].c;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}

