#include<bits/stdc++.h>
using namespace std;
long long a[110][110],b[100000];
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long m,n,js=0,c=m;
cin>>m>>n;
for(int i=1;i<=m*n;i++)cin>>b[i];
long long f=b[1];
sort(b,b+m*n+1);
for(int i=1;i<=m;i++)
{
  if(i%2==0)c=m;
for(int j=1;j<=n;j++)
{
    if(i%2==1){
    a[j][i]=b[m*n-js];
    js++;
    }
    if(i%2==0)
    {
        a[j][i]=b[m*n-js-c+1];
        js++;c-=2;
    }
}
}
for(int i=1;i<=m;i++)
{
for(int j=1;j<=n;j++)
{
      if(a[j][i]==f)cout<<i<<" "<<j;
  }
}

return 0;
}

