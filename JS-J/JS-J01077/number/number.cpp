#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int b[1000001]={0},t=0;
string a;
cin>>a;
int len=a.size();
for(int i=0;i< len;i++)
{
if(a[i]>='0'&&a[i]<='9')
{
t++;
b[t]=int(a[i])-48;
}
}
sort(b,b+t+1);
for(int i=t;i>0;i--)
{
	cout<<b[i];
}
return 0;
}
