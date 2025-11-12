#include<bits/stdc++.h>
using namespace std;
int n,t,m,sum,m2,m3;
struct ss{
    int a,b,c,d1,d2,d3;
    bool b2=true;
};ss d[100010];
bool cmp1(ss a,ss b)
{
   return abs(abs(a.a-a.b)-a.c)>abs(abs(b.a-b.b)-a.c);
     //if(abs(a.a-a.b)!=abs(b.a-b.b)) //else if(abs(a.a-a.c)!=abs(b.a-b.c)) return abs(abs(a.a-a.c)>abs(b.a-b.c));
}
//bool cmp2(ss a,ss b)
//{
 //   if(abs(a.b-a.a)!=abs(b.b-b.a)) return abs(a.b-a.a)>abs(b.b-b.a);
 //   else if(abs(a.b-a.c)!=abs(b.b-b.c)) return abs(abs(a.b-a.c)>abs(b.b-b.c));
//}
//bool cmp3(ss a,ss b)
//{
    //if(abs(a.c-a.b)!=abs(b.c-b.b)) return abs(a.c-a.b)>abs(b.c-b.b);
    //else if(abs(a.a-a.c)!=abs(b.a-b.c)) return abs(abs(a.c-a.a)>abs(b.c-b.a));
//}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        m=m2=m3=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i].a>>d[i].b>>d[i].c;
            d[i].b2=true;
            if(d[i].a>=d[i].b&&d[i].b>=d[i].c){
                d[i].d1=1;
                d[i].d2=2;
                d[i].d3=3;
            }
            else if(d[i].a>=d[i].c&&d[i].c>=d[i].b){
                d[i].d1=1;
                d[i].d2=3;
                d[i].d3=2;
            }
            else if(d[i].b>=d[i].a&&d[i].a>=d[i].c)
            {
                d[i].d1=2;
                d[i].d2=1;
                d[i].d3=3;
            }
            else if(d[i].b>=d[i].c&&d[i].c>=d[i].a)
            {
                d[i].d1=3;
                d[i].d2=1;
                d[i].d3=2;
            }
            else if(d[i].c>=d[i].a&&d[i].a>=d[i].b)
            {
                d[i].d1=2;
                d[i].d2=3;
                d[i].d3=1;
            }
            else if(d[i].c>=d[i].b&&d[i].b>=d[i].a)
            {
                d[i].d1=3;
                d[i].d2=2;
                d[i].d3=1;
            }
        }
        sort(d+1,d+1+n,cmp1);
       // for(int i=1;i<=n;i++)
     //   {
      //      cout<<d[i].a<<" "<<d[i].b<<" "<<d[i].c<<endl;
       // }
       for(int i=1;i<=n;i++)
        {
            if(m>0&&d[i].d1==1&&d[i].b2==true)
            {
                d[i].b2=false;
                sum+=d[i].a;
                m--;
                //cout<<i<<endl;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(m2>0&&d[i].d2==1&&d[i].b2==true)
            {
                d[i].b2=false;
                sum+=d[i].b;
                m2--;
              //  cout<<i;
            }
        }
         for(int i=1;i<=n;i++)
        {
            if(m3>0&&d[i].d3==1&&d[i].b2==true)
            {
                d[i].b2=false;
                sum+=d[i].c;
                m3--;
              //  cout<<i;
            }
        }
        //dierci
        for(int i=1;i<=n;i++)
        {
            if(m>0&&d[i].d1==2&&d[i].b2==true)
            {
                d[i].b2=false;
                sum+=d[i].a;
                m--;
             //   cout<<i<<endl;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(m2>0&&d[i].d2==2&&d[i].b2==true)
            {
                d[i].b2=false;
                sum+=d[i].b;
                m2--;
              //  cout<<i;
            }
        }
         for(int i=1;i<=n;i++)
        {
            if(m3>0&&d[i].d3==2&&d[i].b2==true)
            {
                d[i].b2=false;
                sum+=d[i].c;
                m3--;
             //   cout<<i;
            }
        }
        //disanci
        for(int i=1;i<=n;i++)
        {
            if(m>0&&d[i].d1==3&&d[i].b2==true)
            {
                d[i].b2=false;
                sum+=d[i].a;
                m--;
             //   cout<<i<<endl;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(m2>0&&d[i].d2==3&&d[i].b2==true)
            {
                d[i].b2=false;
                sum+=d[i].b;
                m2--;
              //  cout<<i;
            }
        }
         for(int i=1;i<=n;i++)
        {
            if(m3>0&&d[i].d3==3&&d[i].b2==true)
            {
                d[i].b2=false;
                sum+=d[i].c;
                m3--;
            //    cout<<i;
            }
        }
        cout<<sum<<endl;

}
    return 0;

}
