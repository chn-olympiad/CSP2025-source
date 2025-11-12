#include<bits/stdc++.h>
using namespace std;
int main(){
 freopen(" polygon.in","r",stdin);
 freopen(" polygon.out","w",stdout);
 int n,a[100000],max=0;
 cin>>n;
 for(int i=1;i<=n;i++) 
 cin>>a[i];
  for(int i=1;i<=n;i++) 
  if(max<=a[i]) max=a[i];
  sort(a+1,a+n+1);
 if(n<3) cout<<"0";
 if(n==3&&a[1]+a[2]>max) cout<<"1";
else cout<<"0";
}