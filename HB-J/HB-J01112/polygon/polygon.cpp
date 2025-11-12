#include<bits/stdc++.h>
using namespace std;
int n,a[6000],m=-1,sum=0,b[6000],c[6000];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    sum+=a[i];
    m=max(m,a[i]);
}
if(n<3){
    cout<<0;
    return 0;
}
if(n==3){
    if(sum>m*2){
        cout<<1;
    }
    else{
      cout<<0;
    }
}
return 0;
}
