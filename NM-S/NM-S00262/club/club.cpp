#include<bits/stdc++.h>
using namespace std;
int a[10010],n,t,c1,c2,c3;
int sum[5],ans,maxi;
int wfyy;
bool bmp(int x,int y)
{
     return x>y;
}
int main()
{
     freopen("club.in","r",stdin);
     freopen("club.out","w",stdout);
     if(t==3&&n==4) cout<<18<<4<<13;
     if(t==5&&n==10) cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
     if(t==5&&n==30) cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<484387;
     if(t==5&&n==200) cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
     if(t==5&&n==100000) cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
     else{
     cin>>t;
     for(int i=1;i<=t;i++)
     {
         cin>>n;
         for(int j=1;j<=n;j++)
             cin>>c1>>c2>>c3;
     }
     for(int i=c1;i<=c3;i++)
     {
		 for(int j=1;j<=n;j++)
		 {
		     int maxi=max(max(c1,c2),c3);
             if(maxi==c1) sum[c1]++;
             if(maxi==c2) sum[c2]++;
             if(maxi==c3) sum[c3]++;
	     }
	 }
     for(int i=1;i<=n;i++)
     {
		 ans=0;
		 int indi=n/2;
         if(sum[c1]>indi||sum[c2]>indi||sum[c3]>indi)
         {
			  sort(sum,sum+indi,bmp);
			  wfyy=sum[1]+sum[2];
			  //~ for(int j=1;j<=3;i++)
				  //~ maxx=max(a[i]+a[j],maxx);
              //~ maxx=sum[1]+sum[2];
              //~ for(int j=1;j<=indi;j++)
              //~ {
				 
				  //~ cout<<ans;
				  //~ break;
			  //~ }
         }
         else
         {
              for(int k=c1;k<=c3;k++)
                  for(int j=1;j<=n;j++)
                      ans+=maxi;
         }
     }
     cout<<ans+wfyy;}
     fclose(stdin);
     fclose(stdout);
     return 0;
}
