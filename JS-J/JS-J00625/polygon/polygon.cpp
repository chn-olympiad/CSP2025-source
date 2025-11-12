#include<bits/stdc++.h>
using namespace std;
int n,a[50005],b[50005],c[50005];long long cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.in","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    cin>>a[i];
    }
    sort(a,a+n);
    b[0]=0;
    for(int i=1;i<=n;i++){
    b[i]=b[i-1]+a[i-1];
    }
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }
    for(int i=0;i<n-2;i++){
    for(int j=i+3;j<=n;j++){
    if(b[j]-b[i]>2*a[j-1]){
            cnt+=c[a[i]];
    cnt=cnt%998244353;

    }
    }
    }
    cout<<cnt;
return 0;
}
