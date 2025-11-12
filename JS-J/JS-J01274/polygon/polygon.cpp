#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],maxn[N][N],ans,sum[N][N],maxnn=0;
long long lj(int x){
    long long sum=0;
    for(int i=n-x-1;i>=0;i--)sum+=i;
        return sum;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    maxn[i][i]=a[i];
    sum[i][i]=a[i];
    maxnn=max(maxnn,a[i]);
}
if(maxnn==1){
    long long ans=0;
for(int i=1;i<=n;i++){
 ans+=lj(i);
}
cout<<ans%998244353;
return 0;
}
for(int len=2;len<=n;len++){
    for(int i=1;i+len-1<=n;i++){
        int j=i+len-1;
        maxn[i][j]=max(maxn[i][j-1],a[j]);
        sum[i][j]=sum[i][j-1]+a[j];
    }
}
long long ans=0;
for(int len1=1;len1<=n;len1++){
    for(int i=1;i+len1-1<=n;i++){
        int j=i+len1-1;
        for(int len2=1;len2<=n;len2++){
            for(int l=1;l+len2-1<=n;l++){
                int r=l+len2-1;
                if(l>j&&sum[i][j]+sum[l][r]>2*max(maxn[i][j],maxn[l][r]))ans++;
            }
        }
    }
}
cout<<(ans/2)%998244353;
return 0;
}
