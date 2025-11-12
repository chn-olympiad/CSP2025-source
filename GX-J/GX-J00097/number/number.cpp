#include<bits/stdc++.h>
using namespace std;
long long shu[29999999]={0},g=0,pd[29999999]={0};
bool aq(int a,int b)
{
return a>b;
}
int main()
{
freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
string s;
cin>>s;

for(int i=0;i<s.size();i++)
{
   g++;
   if(s[i]>='0'&&s[i]<='9')
   {

      shu[i]=(int)s[i]-48;
       pd[i]=1;
   }

}
for(int i=0;i<g;i++)
{
  for(int e=0;e<g;e++)
{

   if(shu[e]<shu[e+1])
   {
       swap(shu[e],shu[e+1]);
       swap(pd[e],pd[e+1]);


   }

}


}
/*for(int i=0;i<g;i++)
{

         cout<<shu[i];



}*/
for(int i=0;i<g;i++)
{
    if(pd[i]==1)
    {
         cout<<shu[i];
    }


}
return 0;
}
