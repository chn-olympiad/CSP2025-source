#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[500001]={};//yhh1[500001],yhh2[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,ans=0;
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<n;i++){
        long long yhh=a[i];
        if(yhh==k and b[i]!=1){
            ans++;
            b[i]=1;
        }
        for(long long j=i+1;j<=n;j++){
            yhh=yhh xor a[j];
            if(b[i]!=1 and b[j]!=1 and yhh==k){
                ans++;
                for(long long k=i;k<=j;k++){
                    b[k]=1;
                }
            }
        }
    }
   // long long yh1=a[1],yh2=a[n];
  //  yhh1[1]=yh1;
 //   yhh2[1]=yh2;
 //   for(long long i=1;i<n;i++){
 //       for(long long j=1;j<i;j++){
  //          yh1=(yh1) xor (a[j+1]);
  //          yhh1[i]=yh1;
  //      }
 //       for(long long j=n;j>=i+1;j++){
 //           yh2=(yh2) xor (a[j-1]);
 //           yhh2[i]=yh2;
  //      }
 //       if(yhh1[i]==k and yhh2[i]==k){
  //          ans++;
 //       }
  //  }
    cout<<ans;
    return 0;
}
