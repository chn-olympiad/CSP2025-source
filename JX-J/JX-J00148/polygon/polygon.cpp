#include<bits/stdc++.h>
using namespace std;
int n,a[10005],k=1;
long long jc(int x){
    long long sum=1;
    for(int i=1;i<=x;i++){
        sum*=i;
    }
    return sum;
}
long long bt(int x){
    long long sum1=0;
    for(int i=3;i<=x;i++){
        sum1=sum1+jc(x)/(jc(x-i)*jc(i));
    }
    return sum1;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.ans","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            k=0;
        }
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
            cout<<1;
            return 0;
        }
    }
    if(k==1){
        cout<<bt(n)%998244353;
        return 0;
    }
    return 0;
}
