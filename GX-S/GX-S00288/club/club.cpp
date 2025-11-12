#include<bits/stdc++.h>
using namespace std;
int HK;
int n,my=0,zd=0,r[4]={0},z=0;
struct tx
{
    int b1;
    int b2;
    int b3;
    int d;
    int c;
    int dw;
    int zx;
    int cj=0;
} x[100001];
bool cmp(tx a,tx b)
{
    return a.d>b.d;
}
bool cmp1(tx a,tx b)
{
    return a.b1>b.b1;
    return a.b2>b.b2;
    return a.b3>b.b3;
}
bool cmp2(tx a,tx b)
{
    return a.b2>b.b2;
    return a.b1>b.b1;

    return a.b3>b.b3;
}
bool cmp3(tx a,tx b)
{
    return a.b3>b.b3;
    return a.b1>b.b1;
    return a.b2>b.b2;

}
int main()
{
    freopen("club.in","w",stdin);
    freopen("club.out","r",stdout);
    cin>>HK;
    HK++;
    while(HK--)
    {
        z=0;
        my=0;
        zd=0;
        for(int i=1;i<=3;i++)
        {
            r[i]=0;
        }
      cin>>n;
      for(int i=1;i<=n;i++)
      {
          cin>>x[i].b1>>x[i].b2>>x[i].b3;

          if(x[i].b1>x[i].b2&&x[i].b1>x[i].b3)
          {
              x[i].d=x[i].b1;
              x[i].dw=1;
          }
          if(x[i].b2>x[i].b1&&x[i].b2>x[i].b3)
          {
              x[i].d=x[i].b2;
              x[i].dw=2;
          }
          if(x[i].b3>x[i].b2&&x[i].b3>x[i].b1)
          {
              x[i].d=x[i].b3;
              x[i].dw=3;
          }
          zd=abs(x[i].b3-x[i].b2);
          x[i].zx=x[i].b1;
          if(abs(x[i].b3-x[i].b1)>zd)
          {
              zd=abs(x[i].b3-x[i].b1);
              x[i].zx=x[i].b2;
          }
          if(abs(x[i].b2-x[i].b1)>zd)
          {
              zd=abs(x[i].b2-x[i].b1);
              x[i].zx=x[i].b3;
          }
          x[i].c=zd;
      }
      sort(x+1,x+1+n,cmp);
     // for(int i=1;i<=n;i++)
     // {
    //      cout<<x[i].b1<<x[i].b2<<x[i].b3<<endl;

      //}
      sort(x+1,x+1+n,cmp1);
      /*for(int i=1;i<=n;i++)
      {
          cout<<x[i].b1<<x[i].b2<<x[i].b3<<endl;

      }*/
      for(int i=1;i<=n;i++)
        {
              if(x[i].b1==x[i].d&&r[1]<n/2)
              {
                  my+=x[i].b1;
                  x[i].b1=-1;
                  r[1]++;
                  x[i].cj++;
              }
              z++;
              if(r[1]>n/2)
                x[i].b1=-1;
        }
         sort(x+1,x+1+n,cmp2);
         /*for(int i=1;i<=n;i++)
      {
          cout<<x[i].b1<<x[i].b2<<x[i].b3<<endl;

      }*/
        for(int i=1;i<=n;i++)
        {
              if(x[i].b2==x[i].d&&r[2]<n/2)
              {
                  my+=x[i].b2;
                  x[i].b2=-1;
                  r[2]++;
                  x[i].cj++;
              }
              z++;
              if(r[2]>n/2)
                x[i].b2=-1;
        }
        sort(x+1,x+1+n,cmp3);
        /*for(int i=1;i<=n;i++)
        {
          cout<<x[i].b1<<x[i].b2<<x[i].b3<<endl;

        }*/
        for(int i=1;i<=n;i++)
        {
            z++;
              if(x[i].b3==x[i].d&&r[3]<n/2)
              {
                  my+=x[i].b3;
                  x[i].b3=-1;
                  r[3]++;
                 x[i].cj++;
              }
              if(r[3]>n/2)
                x[i].b3=-1;
        }
        int big=my;
        my=0;
      int fn=n,cz=0,zz=0;
      for(int i=1;i<=n/2;i++)
      {
          cz+=x[i].c;
      }
      for(int i=n/2+1;i<=n;i++)
      {
          zz+=x[i].d;
      }
     // cout<<zz<<" "<<cz<<endl;
      if(zz>=cz)
      {
          while(fn>n/2)
          {
              my+=x[fn].d;
              if(x[fn].dw==1)
              {
                  x[fn].b1=-1;
              }
              if(x[fn].dw==2)
              {
                  x[fn].b2=-1;
              }
              if(x[fn].dw==3)
              {
                  x[fn].b3=-1;
              }
              x[fn].cj++;
              r[x[fn].dw]++;
              z++;
              fn--;
          }
          for(int i=1;i<=n/2;i++)
          {
              x[i].d=x[i].zx;
          }
      }
      sort(x+1,x+1+n,cmp1);
      /*
      for(int i=1;i<=n;i++)
      {
          cout<<x[i].b1<<x[i].b2<<x[i].b3<<endl;

      }
      */
      for(int i=1;i<=n;i++)
        {
              if(x[i].b1==x[i].d&&r[1]<n/2)
              {
                  my+=x[i].b1;
                  x[i].b1=-1;
                  r[1]++;
                  x[i].cj++;
              }
              z++;
              if(r[1]>n/2)
                x[i].b1=-1;
        }
         sort(x+1,x+1+n,cmp2);
        for(int i=1;i<=n;i++)
        {
              if(x[i].b2==x[i].d&&r[2]<n/2)
              {
                  my+=x[i].b2;
                  x[i].b2=-1;
                  r[2]++;
                  x[i].cj++;
              }
              z++;
              if(r[2]>n/2)
                x[i].b2=-1;
        }
        sort(x+1,x+1+n,cmp3);
        for(int i=1;i<=n;i++)
        {
            z++;
              if(x[i].b3==x[i].d&&r[3]<n/2)
              {
                  my+=x[i].b3;
                  x[i].b3=-1;
                  r[3]++;
                 x[i].cj++;
              }
              if(r[3]>n/2)
                x[i].b3=-1;
        }
        if(big>my)
        {
            cout<<big<<endl;
        }
        else cout<<my<<endl;
    }
    return 0;
}
