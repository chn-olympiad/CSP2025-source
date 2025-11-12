#include<bits/stdc++.h>
using namespace std;
int n;
int a[5100];
int  hanshu(int a){
long long int sum=0;
if(a-2<3) return 2;
for(int i=1;i<=a-2;i++){
    sum+=i;
}
return sum+1;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long int sum=hanshu(n);
    long long int ans=sum;
    if(sum-4<=0){
        ans++;
    }
   else{ for(long long int i=sum;i>=1;i-=4){
        ans+=sum%998224553;
    }
   }
    cout<<ans%998224553;
return 0;
}
