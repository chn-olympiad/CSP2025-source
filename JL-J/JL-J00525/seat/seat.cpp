#include<bits/stdc++.h>
using namespace std;
#define N 105
#define M 105
long long a[N*M],n,m,h,l,xm,xmj;
bool cmp(long long x,long long y)
{
	return x>=y;
}
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)cin>>a[i];
xmj=a[1];
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=n*m;i++)if(a[i]==xmj)xm=i;

l=(xm-1)/n+1;
if(l%2){
h=(xm-1)%n+1;
}
else
{
	h=n-((xm-1)%n);
}
cout<<l<<" "<<h<<endl;
return 0;
}
