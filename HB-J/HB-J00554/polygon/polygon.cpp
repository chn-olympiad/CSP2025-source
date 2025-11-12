#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen(polygon.in,'r',stdin);
freopen(polygon.out,'w',stdout);
int n,m,sum=0,sum1=0,sum2=0;
cin>>n>>m;
int a[n];
for(int i=1;i<=n;i++)
{
cin>>a[i];
}
for(int i=1;i<=n;i++)
{
 sum1++;
}
sort(a+1,a+n+1);
for(int i=n;i>=m-1;i--)
{
 sum2++;
}
for(int i=1;i<=n;i++)
{
if(m>3 && sum1>2*sum2)
{
sum++;
}
cout<<sum;
return 0;
}
