#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m, n,zongr,max=0;
cin>>m>>n;
zongr=m*n;
int xr,fs[zongr-1];
cin>>xr;
int min=xr;
scanf("%d",fs);
for(int i=1;i<zongr;i++)
{
if(max<fs[i])//最大值 
max=fs[i];
if(min>fs[i])//最小值 
min=fs[i];
}
if(xr>max)
cout<<1<<" "<<1;
if(min==xr)
cout<<m<<" "<<n; 

int max[zongr-1]={0};
for(int j=1;j<zongr;j++)
{
for(int d=0;d<zongr;d++)	
if(	max1[j] < fs[d])
max[j]=fs[d];
}








return 0;
 } 
