#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],cnt,ans;
signed main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==1) ans++;
}
if(ans==n){
    cout<<n/2;
    return 0;
}
int i=1,j=1,sum=a[1];
while(j<n){
    if(sum<k&&j<n){
        j++;
        sum^=a[j];
    }
    if(sum==k){
        cnt++;
    }
    if(sum>=k&&i<=n){
        sum^=a[i];
        i++;
    }
}
while(i<j){
    sum^=a[i];
    i++;
    if(sum==k){
        cnt++;
    }
}
cout<<cnt;
return 0;
}
