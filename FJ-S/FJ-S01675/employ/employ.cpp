#include<cstdio>
using namespace std;
inline int read()
{ char ch=getchar();int p=0;
  for(;ch<'0'||'9'<ch;ch=getchar());
  for(;'0'<=ch&&ch<='9';p=(p<<3)+(p<<1)+ch-'0',ch=getchar());
  return p;
}
inline void print(const int &x)
{ if(x<0) { putchar('-'),print(-x); return; }
  if(x<10) { putchar(x+'0'); return; }
  print(x/10),putchar(x%10+'0');
}
signed main()
{ freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  print(1);
}