#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
int main()
{freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)
cin>>a[i];
int r=a[1],x=0;
for(int i=1;i<=n*m;i++)
  for(int j=i;j<=n*m;j++)
   if(a[i]<a[j])swap(a[i],a[j]);
for(int i=1;i<=m*n;i++){if(a[i]==r)x=i;break;}
if((x%(2*n))>n)
cout<<2*(x/(2*n))+2<<" "<<2*n+1-x%(2*n)<<endl;
else cout<<2*(x/(2*n))+1<<" "<<x%(2*n)<<endl;
return 0;


}
