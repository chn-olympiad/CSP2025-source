#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int s;
int a[100];
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i];
s+=a[i];
}
if(n<3)
{
cout<<0;
}
for(int i=1;i<=n;i++)
{
if(m<a[i])
{
	m=a[i];
}	
}
if(2*m<s)
{
	cout<<1;
}
else
{
	cout<<0;
}
return 0;
}
