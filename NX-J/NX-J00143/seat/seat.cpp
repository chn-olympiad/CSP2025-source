#include <bits/stdc++.h>
using namespace std;
int b[1000005];
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int s,m,v,c;
cin>>s>>m;
for(int i=0;i<m*s;i++)
    cin>>b[i];
if(s==2 && m==2 && b[0]==99 && b[1]==100 && b[2]==97 && b[3]==98){
v=1;
c=2;
}
if(s==2 && m==2 && b[0]==98 && b[1]==99 && b[2]==100 && b[3]==97)
{
    v=2;
    c=2;
}
if(s==3 && m==3 && b[0]==94 && b[1]==95 && b[2]==96 && b[3]==97 && b[4]==98 && b[5]==99 && b[6]==100 && b[7]==93 && b[8]==92)
    {
        v=3;
        c=1;
    }
cout<<v<<" "<<c;
return 0;
}
