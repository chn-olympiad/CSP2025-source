#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=-1;
    int cnt1=0,cnt0=0,ans=0;
    if(k==0){
       for(int i=1;i<=n+1;i++){
           if(a[i]==0){
              cnt0++;
              ans=ans+cnt1/2;
              cnt1=0;
           }
           if(a[i]==1){
               cnt1++;
               ans=ans+cnt0;
               cnt0=0;
           }
           if(a[i]==-1){
              ans=ans+cnt1/2;
              ans=ans+cnt0;
           }
       }
    }
    if(k==1){
       for(int i=1;i<=n;i++){
           if(a[i]==1)cnt1++;
       }
       ans=cnt1;
    }
    cout<<ans<<endl;
    return 0;
}
