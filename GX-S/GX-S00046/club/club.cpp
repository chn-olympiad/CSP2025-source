#include<bits/stdc++.h>
using namespace std;
long long s1[29999999],s2[29999999],s3[29999999],myd=0,dgsx=0,s1rs=0,s2rs=0,s3rs=0;
long long drzd[29999999]={0},drde[29999999]={0},drds[29999999]={0};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
     int t;cin>>t;
     int rs[6];
     for(int i=1;i<=t;i++)
     {
         cin>>rs[i];
         dgsx=rs[i]/2;
         for(int e=1;e<=rs[i];e++)
         {
             cin>>s1[e]>>s2[e]>>s3[e];


            if(s1[e]>=s2[e]&&s1[e]>=s3[e])
            {
                drzd[e]=s1[e];
                s1rs++;
            }
              if(s2[e]>=s3[e]&&s2[e]>=s1[e])
            {
                drzd[e]=s2[e];
                s2rs++;
            }
              if(s3[e]>=s2[e]&&s3[e]>=s1[e])
            {
                drzd[e]=s3[e];
                s3rs++;
            }
            //2w
           if(s1[e]<=s2[e]&&s1[e]>=s3[e] ||s1[e]<=s3[e]&&s1[e]>=s2[e] )
            {
                drde[e]=s1[e];
            }
           if(s2[e]<=s3[e]&&s2[e]>=s1[e] ||s2[e]<=s1[e]&&s2[e]>=s3[e])
            {
                drde[e]=s2[e];
            }
            if(s3[e]<=s2[e]&&s3[e]>=s1[e] ||s3[e]<=s1[e]&&s3[e]>=s2[e])
            {
                drde[e]=s3[e];
            }
            //3w
           if(s1[e]<=s2[e]&&s1[e]<=s3[e]  )
            {
                drds[e]=s1[e];
            }
           if(s2[e]<=s3[e]&&s2[e]<=s1[e] )
            {
                drds[e]=s2[e];
            }
            if(s3[e]<=s2[e]&&s3[e]<=s1[e] )
            {
                drds[e]=s3[e];
            }
       myd=myd+drzd[e];

         }
        cout<<myd<<endl;
        myd=0;
     }
    return 0;
}
