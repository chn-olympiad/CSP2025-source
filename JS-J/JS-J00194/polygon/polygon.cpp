#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
void fff(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
}
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,ans;
int a[5005];
int dp[5005][5005];
int s[5005];
int q[5005],c;
void dfs(int s,int maxn,int sum,int chs){
    if(chs>=3&&sum>maxn*2&&s>n){
        ++ans; ans%=mod;
        return;
    }
    else if(s>n) return;
    dfs(s+1,max(maxn,a[s]),sum+a[s],chs+1);
    dfs(s+1,maxn,sum,chs);
}
int main(){
    fff();
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    dfs(1,0,0,0);
    printf("%d\n",ans);
    return 0;
}
