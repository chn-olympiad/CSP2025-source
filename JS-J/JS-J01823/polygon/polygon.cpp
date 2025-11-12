#include <bits/stdc++.h>
using namespace std;
long long n;
int a[500002];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
cout<<n*(n-1)*(n-2)/6+n*(n-1)*(n-2)*(n-3)/24;
  return 0;
}
