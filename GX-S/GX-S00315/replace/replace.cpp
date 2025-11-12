#include<bits/stdc++.h>
#define N 200001
using namespace std;
int read()
{
  int x=0,f=1;char c=getchar();
  while(!isdigit(c))
  {
      if(c=='-') f=-1;
      c=getchar();
  }
  while(isdigit(c))
  {
      x=x*10+c-'0';
      c=getchar();
  }
  return x*f;
}
int n,q,ans;
struct nx
{
  int al1,ar1;
  int al2,ar2;
}a[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),q=read();
    for(int i=1;i<=n;i++)
    {
      char c;
      while(c!='a'&&c!='b')
        c=getchar();
      while(c=='a')
        a[i].al1++,c=getchar();
      c=getchar();
      while(c=='a')
        a[i].ar1++,c=getchar();

      while(c!='a'&&c!='b')
        c=getchar();
      while(c=='a')
        a[i].al2++,c=getchar();
      c=getchar();
      while(c=='a')
        a[i].ar2++,c=getchar();
    }
    while(q--)
    {
      int l1=0,r1=0,l2=0,r2=0;
      char c;
      while(c!='a'&&c!='b')
        c=getchar();
      while(c=='a')
        l1++,c=getchar();
      c=getchar();
      while(c=='a')
        r1++,c=getchar();

      while(c!='a'&&c!='b')
        c=getchar();
      while(c=='a')
        l2++,c=getchar();
      c=getchar();
      while(c=='a')
        r2++,c=getchar();
      for(int i=1;i<=n;i++)
      {
        if(l1>=a[i].al1&&r1>=a[i].ar1)
        {
            int dl=l1-a[i].al1+a[i].al2;
            int dr=r1-a[i].ar1+a[i].ar2;
            if(dl==l2&&dr==r2)
              ans+=1;
        }
      }
      printf("%d\n",ans);
      ans=0;
    }
    return 0;
}
