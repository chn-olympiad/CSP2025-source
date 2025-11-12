#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
return a>b;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
long long t;
cin>>t;
for(long long i=1;i<=t;i++){
    long long n;
    cin>>n;
    long long a[n+1];
    for(long long j=1;j<=n;j++){
            int h,f,ff;
    cin>>h>>f>>ff;a[j]=max(h,max(f,ff));
    }
    sort(a+1,a+n+1,cmp);
    long long ans=0;
     for(long long j=1;j<=n/2;j++){
      ans+=a[j];
    }
    cout<<ans<<endl;
}
}
