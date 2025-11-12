#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005],b;
signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
while(t--){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b>>b;
    }
    sort(a+1,a+n+1);
    int sum=0;
    for(int i=n;i>n/2;i--){
        sum+=a[i];
    }
    cout<<sum<<"\n";
}
return 0;
}
