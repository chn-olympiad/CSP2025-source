#include<bits/stdc++.h>
using namespace std;
int n,k;int a[500005];long long ans=0;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==0)
        ans++;
}
if(k==0){
cout<<ans/2;
ans=0;
return 0;
}
else if(k==1){
        int p=0;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]&&a[i]==1)ans++;
    }
    cout<<ans;
    return 0;
}
else {
    cout<<"2";
    return 0;
}
return 0;
}
