#include<bits/stdc++.h>
#define ftsydj 114514
using namespace std;
const int Mod=998244353;
int n,a[5028],b[5028],ans;
int check(int m){
    int i,s=0;
    for(i=1;i<m;++i){
        s+=b[i];
        if(s==2)return 0;
    }
    return 1;
}
void solve(){
    int i,m=n,s=0;
    while(!b[m])m--;
    if(check(m))return;
    for(i=1;i<m;++i)
        s+=a[i]*b[i];
    if(s>a[m])ans=(ans+1)%Mod;
}
void dfs(int x){
    if(x>n){
        solve();return;
    }
    for(int i=0;i<2;++i){
        b[x]=i;
        dfs(x+1);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    memset(b,1,sizeof(b));
    dfs(1);
    cout<<ans<<endl;
    return 0;
}

/*
Oh shit!
It's too difficult.
I even can't solve it conpletely.
Creater, fuck your mother.
Damn it!
*/

/*
      **
      **
      **
      **
      **
** ** ** ** **
** ** ** ** **
**************
**************
**************
**************
