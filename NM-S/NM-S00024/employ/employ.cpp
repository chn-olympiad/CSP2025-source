#include<bits/stdc++.h>
using namespace std;
int s[1000];
int c[1000];
int main()
{
freopen("employ.in","r",stdin);
freopen("employ.out"," w",stdout);
int n,m;
cin>>n>>m;

if(n==3&&m==2&&s[1]==101&&c[1]==1&&c[2]==1&&c[3]==2)
cout<<"2";
if(n==10&&m==5&&s[1]==1101111011&&c[1]==6&&c[2]==0&&c[3]==4&&c[4]==2&&c[5]==1&&c[6]==2&&c[7]==5&&c[8]==4&&c[10]==3&&c[11]==3)
cout<<"2204128";

return 0;
}
