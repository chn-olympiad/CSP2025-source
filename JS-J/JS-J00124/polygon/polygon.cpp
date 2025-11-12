#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
   long long n,cnt=0;
   cin>>n;
   int a[n+5],pre[n+5];
   if(n<3){
        cout<<0;
        return 0;
   }
   for(int i=1;i<=n;i++){
    cin>>a[i];
    if(i==1)pre[i]=a[i];
   }
   sort(a+1,a+n+1);
   for(int i=1;i<n;i++){
        if(pre[i]>a[n]*2)cnt++;
   }
   for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i==k||j==k)continue;
                if(pre[i]-pre[j]+a[i]+a[k]>2*a[k])cnt++;
            }
        }
   }
   cout<<cnt%998244353;
    return 0;
}
