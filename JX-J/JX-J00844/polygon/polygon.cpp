#include<bits/stdc++.h>
using namespace std;
long long n,ans,sum,b,c,d;
int a[5006],zd,zd1;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    zd=max(zd,a[i]);
}
if(zd>1){
    for(int i=1;i<=n;i++){
        sum=a[i];
        zd1=a[i];
        for(int j=i+1;j<=n;j++){
            sum+=a[j];
            zd1=max(zd1,a[j]);
            for(int k=j+1;k<=n;k++){
            if(sum+a[k]>2*max(zd1,a[k])){
                ans++;
            }
            }
            sum-=a[j];
            zd=a[i];
        }
    }
}
else{
for(long long i=3;i<=n;i++){
d=max(i,n-i);
c=min(i,n-i);
b=1;
for(long long j=d+1;j<=n;j++){
b=b*j%998244353;
}
for(long long j=1;j<=c;j++){
    b/=j;
}
ans+=b;
ans%=998244353;
}
}
cout<<ans;
}
