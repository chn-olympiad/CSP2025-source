#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
  {int w=0,f=1;
  char ch=getchar();
  for(;ch<'0'||ch>'9';ch=getchar())  if(ch=='-')  f=-1;
  for(;ch>='0'&&ch<='9';ch=getchar())  w=(w<<3)+(w<<1)+(ch^48);
  return w*f;
  }
const int N=5e2+10,mod=998244353;
int n,m,p[N],ans,ms[N],c[N];
char ch[N];
int main()
{
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
scanf("%d%d",&n,&m);
scanf("%s",ch+1);
for(int i=1;i<=n;i++)  ms[i]=ch[i]-'0',p[i]=i;
for(int i=1;i<=n;i++)  c[i]=read();
//for(int i=1;i<=n;i++)  printf("%d ",c[i]);
do
  {int x=0,ly=0;
//  for(int i=1;i<=n;i++)  printf("%d ",p[i]);
//  printf("\n");
  for(int i=1;i<=n;i++)  
    if(x>=c[p[i]]||!ms[i])  x++;
    else  ly++;
  if(ly>=m)  ans++;
//  printf("%d\n",ly);
  }while(next_permutation(p+1,p+1+n));
printf("%d",ans);
}
//10 5
//1101111011
//6 0 4 2 1 2 5 4 3 3
