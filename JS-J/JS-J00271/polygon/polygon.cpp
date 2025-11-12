#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],i,cnt;
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin>>n;
   for(i=0;i<n;i++){
        cin>>a[i];
   }
   for(i=7;i<(1<<n);i++){
        long long sum=0,max1=-1,x=i,x0=0,cnt1=0;
        while(x){
            if(x%2==1){
                max1=max(max1,a[x0]);
                sum+=a[x0];
                cnt1++;
            }
            x0++;
            x/=2;
        }
        if(sum>2*max1&&cnt1>=3)cnt++;
        cnt=cnt%998244353;
   }
   cout<<cnt;
   return 0;
}
