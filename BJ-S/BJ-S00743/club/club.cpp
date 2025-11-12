#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("club.in","r",stdin);
freopen("club,out","w",stdout);
int t;
int ja[t],jb[t],jc[t];
int A[t];
cin>>t;
for(int i=0;i<t;i++)
{
     int b=i;
     A[b]=0;
     int n;
     cin>>n;
     int a[t][n][3];
     for(int c=0;c<n;c++)
     {
         cin>>a[b][c][0];
         cin>>a[b][c][1];
         cin>>a[b][c][2];
         if(a[b][c][0]>a[b][c][1]&&a[b][c][0]>a[b][c][2]);
         {
               ja[b]++;
              A[b]+=a[b][c][0];
           }
         else if(a[b][c][1]>a[b][c][0]&&a[b][c][1]>a[b][c][2]);
        {
                   jb[b]++;
                   A[b]+=a[b][c][1];
}
          else if(a[b][c][2]>a[b][c][0]&&a[b][c][2]>a[b][c][1]);
         {
                  jc[b]++;
                  A[b]+=a[b][c][2];
         }
}
}
for(int i=0;i<t;i++)
{
cout<<A[i]<<endl;
}
fclose(stdin);
fclose(stdout);
return 0;
}