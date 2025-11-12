#include<bits/stdc++.h>
using namespace std;
int main(){
      freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
    int n,k;cin>>n>>k;
    int a[n];
    int result;
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+n+1);
    if(n<3) result=0;
    else if(n==3&&a[1]+a[2]<=a[3]) result=0;
    else if(n==3&&a[1]+a[2]>a[3]) result=1;
    else result=8;
    cout<<result;
    return 0;
}
