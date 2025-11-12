#include<bits/stdc++.h>
using namespace std;
int n,k,a[600010],sum=0;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==1){
        sum++;
    }
}
if(sum==n){
    cout<<n/2;
    return 0;
}
if(k==1){
    sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            sum++;
        }
    }
    int num=0;
    for(int i=2;i<=n;i+=2){
        if(a[i]!=a[i-1]){
            num++;
        }
    }
    cout<<max(sum,num);
}
if(k==0){
    sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            sum++;
        }
    }
    int num=0;
    for(int i=2;i<=n;i+=2){
        if(a[i]==a[i-1]){
            num++;
        }
    }
    cout<<max(sum,num);
}
return 0;
}
