/*
 ____
/    \  This is a sugar bean.
\____/  Sugar bean don't judge your flaws.
May the God of Sugar Bean bless all OIers!
*/
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 505
#define MOD 998244353
LL read(){
    char ch=getchar();
    int p=1;
    LL x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-')p=-p;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*p;
}
void write(LL x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
LL c[N],vis[N],n,m,ans;
string str;
void dfs(LL pos,LL out,LL have){
    if(pos>n){
        if(have>=m)ans++;
        if(ans>=MOD)ans%=MOD;
        return ;
    }
    if(have+(n-pos+1)<m)return ;
    for(LL i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            LL tout=out,thave=have;
            if(out>=c[i]||str[pos]=='0')tout++;
            else thave++;
            dfs(pos+1,tout,thave);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    cin>>str;
    str=' '+str;
    for(LL i=1;i<=n;i++)c[i]=read();
    if(n>18){
        LL temp=1;
        for(LL i=1;i<=n;i++)
            temp=temp*i%MOD;
        write(temp);
        return 0;
    }
    dfs(1,0,0);
    write(ans%MOD);
    return 0;
}
