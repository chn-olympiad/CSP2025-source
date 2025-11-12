#include<bits/stdc++.h>
using namespace std;
#define sp putchar(' ')
#define el putchar('\n')
using ll=__int128;
inline ll read(){
    ll x=0;
    int f=1;
    char cc=getchar();
    while(!isdigit(cc)){
        if(cc=='-'){
            f=-f;
        }
        cc=getchar();
    }
    do{
        x=(x<<1)+(x<<3)+(cc^'0');
    }while(isdigit(cc=getchar()));
    return f*x;
}
inline void print(ll x){
    if(x<0){
        putchar('-');
        print(-x);
    }else if(x<10){
        putchar(x^'0');
    }else{
        print(x/10);
        putchar(x%10^'0');
    }
}
const int m=998244353;
int n,a[5005];
int ans,f[5005]={1};
int sum;
void dfs(int t,int sum,int mx){
    if(t>n){
        if(mx*2<sum){
            ++ans;
        }
        return;
    }
    dfs(t+1,sum+a[t],max(mx,a[t]));
    dfs(t+1,sum,mx);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    dfs(1,0,0);
    print(ans);
    el;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
