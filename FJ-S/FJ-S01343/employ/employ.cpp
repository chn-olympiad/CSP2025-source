#include<bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
const int Siz=1<<18;char buf[Siz],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,Siz,stdin),p1==p2)?EOF:*p1++
int read(){
    int a=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') a=a*10+ch-'0',ch=getchar();
    return a;
}
const int N=510,P=998244353;
int n,m,s[N],c[N],a[N],ans,flag=1;
signed main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    n=read(),m=read();char ch=getchar();while(ch!='0'&&ch!='1') ch=getchar();
    for(int i=1;i<=n;i++,ch=getchar()) s[i]=ch-'0',flag&=s[i];
    for(int i=1;i<=n;i++) c[i]=read(),flag&=bool(c[i]),a[i]=i;
    if(m==n){
        if(!flag) return printf("0\n"),0;
        ans=1;for(int i=2;i<=n;i++) ans=1ll*ans*i%P;return printf("%d\n",ans),0;
    }
    do{
        int sum=0;for(int i=1;i<=n;i++) if(!s[i]||sum>=c[a[i]]) sum++;
        ans+=(n-sum>=m);
    }while(next_permutation(a+1,a+n+1));
    return printf("%d\n",ans),0;
    
}