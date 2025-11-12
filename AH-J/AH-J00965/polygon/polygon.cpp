#include <bits/stdc++.h>
using namespace std;
int a[100001],n;
int main(){
 freopen("polygon.in","r",stdin);
 freopen("polygon.out","w",stdout);
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 int sum=0;
 for(int i=1;i<=n;i++)
  sum+=a[i];
 int max=1;
 for(int i=2;i<=n;i++)
  if(a[max]<a[i])max=i;
 if(a[max]*2>=sum)cout<<"0";
 else cout<<"1";
 return 0;
}
