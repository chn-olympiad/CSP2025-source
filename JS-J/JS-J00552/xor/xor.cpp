#include<bits/stdc++.h>
using namespace std;
void read(int &x){
  x=0;
  int f=1;
  char ch;
  do{
    ch=getchar();
    if(ch=='-') f=-1;
  }while(ch<'0'||ch>'9');
  do{
    x=x*10+ch-'0';
    ch=getchar();
  }while(ch>='0'&&ch<='9');
  x*=f;
}
int sta[20],statop;
void write(int x){
  if(!x){puts("0");return;}
  if(x<0){putchar('-');x=-x;}
  for(;x;x/=10) sta[++statop]=x%10;
  for(;statop;) putchar('0'+sta[statop--]);
  putchar('\n');
}
const int N=5e5+5,M=1<<20,INF=0x3f3f3f3f;
int n,k;
int a[N],s[N];
int f[N],g[M],ans;
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  read(n);read(k);
  for(int i=1;i<=n;i++)
    read(a[i]);
  for(int i=1;i<=n;i++)
    s[i]=s[i-1]^a[i];
  for(int i=1;i<M;i++)
    g[i]=-INF;
  for(int i=1;i<=n;i++){
    f[i]=g[k^s[i]]+1;
    ans=max(ans,f[i]);
    g[s[i]]=max(g[s[i]],ans);
  }
  write(ans);
  return 0;
}
//T3 done 9:45
//bu dui 9:50
//dui de dui de 10:02

//zao zhi dao da wan n*n bao li DP you hua yi xia jiu chu zheng jie le
//jiu xian zuo T3 le
//XD
