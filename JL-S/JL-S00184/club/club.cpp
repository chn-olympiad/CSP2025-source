#include<bits/stdc++.h>
using namespace std;
struct p{
    int a,b,c,maxv,minn;
    bool bb;
}people[1000];
bool cmp(p d,p e)
{

    return d.a<e.a;
}
bool cmb(p d,p e)
{

    return d.maxv>e.maxv;
}
int main()
{
    //cout<<"hello,word";

   int n,pa=0,pb=0,pc=0,ans=0;
   cin>>n;
   for(int i=1;i<=n;i++)
   {   int x;
         cin>>x;


         for(int j=1;j<=x;j++)
         {
           cin>>people[j].a>>people[j].b>>people[j].c;
    people[j].maxv=max(people[j].a,people[j].b);
     people[j].minn=min(people[j].a,people[j].b);

        }


           //p[i].manmax(p[i].a)

      if(people[1].b==people[1].c&&people[1].c==0)
              {
                 sort(people+1,people+1+x,cmp);


                 for(int h=x;h>=x/2+1;h--)
                 {

                   ans+=people[h].a;


                 }

             }

        else if(x==2)
           {
           int maxvv;
          if(people[1].maxv>people[2].maxv)
          {
              ans+=people[1].maxv;
              if(people[2].maxv==people[2].a)
              {
                 maxvv=max(people[2].b,people[2].c) ;
                  ans+=maxvv;
              }
                else if(people[2].maxv==people[2].b)
                {
                   maxvv=max(people[2].a,people[2].c);
                    ans+=maxvv;
                }
               else if(people[2].maxv==people[2].c)
                {
                    maxvv=max(people[2].b,people[2].a);
                      ans+=maxvv;

                }

          }

           else if(people[1].maxv<people[2].maxv)
          {
              ans+=people[2].maxv;
              if(people[1].maxv==people[1].a)
              {
                 maxvv=max(people[1].b,people[1].c) ;
                  ans+=maxvv;
              }
                else if(people[1].maxv==people[1].b)
                {
                   maxvv=max(people[1].a,people[1].c);
                    ans+=maxvv;
                }
                else if(people[1].maxv==people[1].c)
                {
                    maxvv=max(people[1].b,people[1].a);
                      ans+=maxvv;

                }

          }

        }
             //if(ans!=0)
           cout<<ans<<endl;
           ans=0;
   }

return 0;
}
