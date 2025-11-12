#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int a,s;
cin>>a>>s;
int d=a*s-1;
int in,cnt=0;
cin>>in;
for(int i=0;i<d;i++)
{
int f;
cin>>f;
if(f>in)
cnt++;
}
cout<<cnt/a+1<<" ";
if((cnt/a+1)%2==0)
{
cout<<s-cnt%a;
}else
{
cout<<cnt%a+1;
}


}
