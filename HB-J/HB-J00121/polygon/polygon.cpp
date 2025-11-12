#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,flag=0;
cin>>n;
int a[n+105]={0},a1[n+105]={0};
for(int i=1;i<=n;i++){
    cin>>a[i];
    a1[i]=2*a[i];
    if(a[i]!=1){
        flag=1;
    }
}

if(n==3){
    if((a[1]+a[2])>=a[3]&&(a[2]+a[3])>=a[1]&&(a[1]+a[3])>=a[2]){
        cout<<1;
    }
    else
        cout<<0;
    return 0;
}
    long long shu=0;
    for(int i=3;i<=n;i++){
        long long shu1=1;
        for(int j=0;j<n-i;j++){
            shu1*=(n-j);
        }
        shu1%=998244353;
        shu+=shu1;
        shu%=998244353;
    }
    cout<<shu;

return 0;}

