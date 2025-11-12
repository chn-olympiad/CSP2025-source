#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long s;
bool f=1;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]!=1)f=0;
}
if(f){
    for(int i=3;i<=n;i++){
        int t=1;
        for(int j=0;j<i;j++){
            t*=n-j;
        }
        for(int j=1;j<=i;j++){
            t/=j;
        }
        s+=t;
        s%=998244353;
    }
cout<<s;
return 0;
}
else if(n<=3){
    if(n<3)cout<<0;
    else if(max(max(a[1],a[2]),a[3])*2<a[1]+a[2]+a[3])cout<<1;
    else cout<<0;
    return 0;
}
return 0;
}
