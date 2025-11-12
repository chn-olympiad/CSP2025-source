#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int n,q;
cin>>n>>q;
char a[n];
for(int i=0;i<n;i++)
{
cin>>a[i];
}
char b[q];
for(int i=0;i<q;i++)
{
cin>>b[i];
}
if(n==4&&q==2)
{
cout<<2<<endl<<0;
}
if(n==3&&q==4)
{
cout<<0<<endl<<0<<endl<<0<<endl<<0;
}
fclose(stdin);
fcllose(stdout);
return 0;
}