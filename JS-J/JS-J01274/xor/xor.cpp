#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,cnt1,cnt0,a[N];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==1)cnt1++;
if(a[i]==0)cnt0++;
}
if(k==0){
        int t=0,ans=0;
    for(int i=1;i<=n;i++){
        if(t==2){
            ans++;
            t=0;
        }
        if(a[i]==0)t=0;
        if(a[i]==1)t++;
    }
    cout<<cnt0+ans;
}
if(k==1)cout<<cnt1;
return 0;
}
