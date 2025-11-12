#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,b[99],x=0,y=0,z=0,c;
int a[99][99][99];
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++)
{cin>>b[i];
for(int h=0;h<b[i];h++)
{
//for(int j=0;j<3;++j)
cin>>a[i][h][1]>>a[i][h][2]>>a[i][h][3];
}
}
 for(int j=0;j<n;++j)
 {c=0;
for(int i=0;i<b[j];++i)
 {if(a[j][i][1]>a[j][i][2])
 if(a[j][i][1]>a[j][i][3])
if(x<n/2)
{c=c+a[j][i][1];
 x=x+1;}
 if(a[j][i][2]>a[j][i][3])
   if(a[j][i][2]>a[j][i][1])
if(y<n/2)
{y=y+1;
c+=a[j][i][2];
}if(a[j][i][3]>a[j][i][2])
if(a[j][i][3]>a[j][i][1]){z=z+1;
c+=a[j][i][3];}
} }
cout<<c<<" ";
return 0;
}
