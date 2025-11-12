#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int k=1,x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')k=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*k;
}
void print(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x<10){
        putchar(x+'0');
        return;
    }
    print(x/10);
    putchar(x%10+'0');
}
const int M=998244353;
const int N=5005;
int n;
int a[N];
int ans;
void dfs(int p,int maxn,int sum,int c){
    if(c+n-p+1<3)return;
    if(p>n){
        if(c>=3&&sum>2*maxn)ans++;
        return;
    }
    dfs(p+1,max(maxn,a[p]),sum+a[p],c+1);
    dfs(p+1,maxn,sum,c);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    dfs(1,0,0,0);
    print(ans);
    return 0;
}