#include <bits/stdc++.h>
using namespace std;
int n,m,a[101];
int main(){
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
 cin>>n>>m;
 for(int i=1;i<=n*m;i++)
  cin>>a[i];
 int pm=1;
 for(int i=2;i<=n*m;i++)
  if(a[1]<a[i])pm++;
 int c=(pm+n-1)/n;
 int r;
 if(c%2==0)
  r=n-(pm-n*(c-1))+1;
 else
  r=pm-n*(c-1);
 cout<<c<<" "<<r;
 return 0;
}
