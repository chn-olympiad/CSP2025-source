#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a1,a2;
long long a[1100];
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++)
{
cin>>a[i];
if(a[i]==0)
{
	a1++;
if(a[i-1]==0)
{
	a1--;
}
}
else if(a[i]==1)
{
	a2++;
if(a[i-1]==1)
{
	a2--;
}
}
cout<<a2<<" ";
}
if(k==0)
{
cout<<a1;
}
else if(k==1)
{
cout<<a2;
}
return 0;
}
