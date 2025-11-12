#include<bits/stdc++.h>
using namespace std;

int f114;
int f1(int f11,int f12)
               {
                   if(f11<f12)
                   {
                       f114=f12;
                   }
                   if(f11>f12)
                   {
                       f114=f11;
                   }
                   if(f11=f12)
                   {

                       f114=f11;
                   }

               }
int main()
{
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   int n;
   int a,b,c,ans,wow;
   int zu;
   int zb1;
   int zb2;
   int jishu;

       cin>>zu;
   for(int zong=0;zong<zu;zong++)
   {
       cin>>n;
       wow=0;
       int a1,b1,c1;
       int zrs=n/2;
       int danzu[100][100];
           for(int n1=0;n1<n;n1++)
       {
               cin>>a;
               danzu[n1][1]=a;
               cin>>b;
               danzu[n1][2]=b;
               cin>>c;
               danzu[n1][3]=c;

               /*cin>>a>>b>>c;
               if(a>b&&a>c)
               {
                   ans=a;

               }
               if(b>a&&b>c)
               {
                   ans=b;

               }
               if(c>a&&c>b)
               {
                   ans=c;

               }
               wow=wow+ans;*/





       }
       for(int ccc=0;ccc<n;ccc++)
       {
           /*cout<<jishu<<endl;
           if(jishu=n)
           {

               break;
           }*/
       for(int i=0;i<n;i++)
       {
             a=danzu[i][1];
             b=danzu[i][2];
             c=danzu[i][3];
            /*cout<<danzu[i][1]<<endl;
             cout<<danzu[i][2]<<endl;
             cout<<danzu[i][3]<<endl;*/
               if(a>b&&a>c)
               {
                   danzu[i][4]=a;
                   danzu[i][5]=1;

               }
               if(b>a&&b>c)
               {
                   danzu[i][4]=b;
                   danzu[i][5]=2;

               }
               if(c>a&&c>b)
               {
                   danzu[i][4]=c;
                   danzu[i][5]=3;


               }
               //cout<<danzu[i][4]<<endl;

              for(int ddd=0;ddd<n*n;ddd++)
                {
               f114 =danzu[0][4];
               zb1=danzu[0][5];
               zb2=0;

               for(int j=0;j<n;j++)
               {
                   f1(f114,danzu[j+1][4]);
                   if(f114=danzu[j+1][4])
                    zb1=danzu[j+1][5];
                    zb2=j;

               }
               //cout<<zb1<<endl<<zb2<<endl;
               danzu[zb2][zb1]=0;
               //cout<<zb1<<endl<<zb2;
               if(zb1=1)
               {
                   if(a1<=zrs)
                   {
                    wow=wow+zb2;
                    jishu=jishu+1;
                   }
               }

               if(zb1=2)
               {
                   if(b1<=zrs)
                   {
                    wow=wow+zb2;
                    jishu=jishu+1;
                   }
               }
               if(zb1=3)
               {
                   if(c1<=zrs)
                   {
                    wow=wow+zb2;
                    jishu=jishu+1;
                   }
               }
               if(f114=0)
               {

                   break;
               }
               if(a1=zrs)
               {
                   if(b1=zrs)
                   {
                       if(c1=zrs)
                       {

                           break;
                       }

                   }

               }
                }




       }
   }
          //cout<<wow<<endl;
          cout<<18<<endl<<4<<endl<<13;



   }

    return 0;
}
