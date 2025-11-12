#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
void write(ll x){
  if(!x){puts("0");return;}
  if(x<0){putchar('-');x=-x;}
  for(;x;x/=10) sta[++statop]=x%10;
  for(;statop;) putchar('0'+sta[statop--]);
  putchar('\n');
}
const int N=5e3+5,MOD=998244353;
int n;
int l[N],maxl;
int p2[N];
int f[N];
ll ans;
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  read(n);
  for(int i=1;i<=n;i++)
    read(l[i]);
  sort(l+1,l+n+1);
  maxl=l[n];
  p2[0]=1;
  for(int i=1;i<=n;i++)
    p2[i]=(p2[i-1]<<1)%MOD;
  f[0]=1;
  for(int i=1;i<=n;i++){
    ll sum=0;
    for(int j=0;j<=l[i];j++) sum=(sum+f[j])%MOD;
    ans=(ans+p2[i-1]-sum+MOD)%MOD;
    for(int j=maxl;j>=0;j--)
      if(j-l[i]>=0) f[j]=(f[j]+f[j-l[i]])%MOD;
  }
  write((ans+MOD)%MOD);
  return 0;
}
//9:23 T4 done
//10:02 finish all

//zui kai shi nei ceng xun huan j xie cheng i le
//tiao le 10min cai fa xian
//noob

//hong cheng lv lv?
//gan jue jin nian CSPJ jian dan hao duo
//xia wu CSPS hui ying ma
//boring...
//666 kao yi ban shu biao huai le
