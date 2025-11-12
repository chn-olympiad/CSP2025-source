#include<bits/stdc++.h>
#define int long long
#define N 5000
#define Mod 998244353
using namespace std;
int n,a[N+5],f[N+5],ans=0;
int read(){
    int f=1,g=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        g=g*10+ch-'0';
        ch=getchar();
    }
    return f*g;
}
void print(int x){
    if(x<0){
        putchar('-');
        x*=-1;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
    return;
}
main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n),f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i]+1;j<=N+1;j++)ans=(ans+f[j])%Mod;
        f[N+1]=f[N+1]*2%Mod;
        for(int j=N;j>=0;j--)f[min(1ll*(N+1),j+a[i])]=(f[min(1ll*(N+1),j+a[i])]+f[j])%Mod;
    }
    print(ans);//,putchar('\n');
    return 0;
}