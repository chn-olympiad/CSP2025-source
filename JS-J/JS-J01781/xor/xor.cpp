#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500007];
long long maxn=-1;
int main(){
   freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(long long i=0;i<n;i++){
        long long sum=a[i];
        long long cnt=0;
        for(long long j=i+1;j<n;j++){
            if(sum==k){
                cnt++;
                sum=a[j];
            }else{
                sum^=a[j];
            }
        }
        maxn=max(maxn,cnt+(sum==k));
    }
    cout<<maxn;
    return 0;
}
