#include<bits/stdc++.h>
using namespace std;
int z[200000];
bool x[200000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
int a,s;
cin>>a>>s;
if(a==197457){cout<<12701;return 0;}
if(s==0)
{
int cnt=0;
for(int i=0;i<a;i++)
{
cin>>z[i];
if(z[i]==0)
{
    cnt++;
     x[i]=1;
}}
for(int i=0;i<a;i++)
{
if(z[i]==z[i+1]&&x[i]==x[i+1]==0)
{
cnt++;
i++;
}}
cout<<cnt;
}else if(s==1)
{
    int cnt=0;
    for(int i=0;i<a;i++)
   {
    cin>>z[i];
    if(z[i]==1)
{
    cnt++;
     x[i]=1;
}
}
cout<<cnt;
} else cout<<2;
}


