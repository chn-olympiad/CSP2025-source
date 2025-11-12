#include<bits/stdc++.h>
using namespace std;
int main( ){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,ans=0,a[10000000];
cin>>n>>m;
for(int i=1;i<=n*m;i++)
{
    cin>>a[i];
    int q=a[i];
}
for(int i=1;i<=n*m;i++)
    for(int j=i+1;j<=n*m;j++)
{
    if(a[i]<a[i+1])
    {
        swap(a[j],a[j+1]);
    }
}



for(int i=1;i<=m;i++)
{
    if(i/2==1)
    {

      for(int j=1;j<=n;j++)
      {
        int t[i][j]=a[ans];
        ans++;
        if(t[i][j]==q)
        {
            cout<<i<<" "<<j<<endl;
            return 0;
        }
      }
    }
}
return 0;
}
