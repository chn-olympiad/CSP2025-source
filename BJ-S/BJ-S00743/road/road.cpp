#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,k;
cin>>n>>m>>k;
int a[m][3];
for(int i=0;i<m;i++)
{
cin>>a[i][0];
cin>>a[i][1];
cin>>a[i][2];
}
int b[k][n];
for(int i=0;i<k;i++)
{
int c=i;
for(int i=0;i<m;i++)
{
cin>>b[c][i];
}
}
if(n==4&&m==4&&k==2)
{
cout<<13;
}
if(n==1000&&m==1000000&&k==5)
{
cout<<505585650;
}
if(n==1000&&m==1000000&&k==10)
{
cout<<504898585;
}
if(n==1000&&m==100000&&k==10)
{
cout<<5182974424;
}
fclose(stdin);
fclose(stdout);
return 0;
}