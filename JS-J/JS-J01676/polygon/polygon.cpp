#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int read(){
    int x=0;
    char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar_unlocked();
    }
    return x;
}
long long ans;
void dfs(int dep,int sum,int p,int maxn){
   if(dep>n){
       if(sum>2*maxn&&p>=3)ans++;
       return;
   }
   dfs(dep+1,sum+a[dep],p+1,max(maxn,a[dep]));
   dfs(dep+1,sum,p,maxn);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
