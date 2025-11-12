#include<bits/stdc++.h>
using namespace std;
int a[5005];
int s[5005];
int maxx[5005][5005];
long long jc(long long cnt,int x){
    long long sum=1;
    for(int i=x;i>=1;i--){
        sum=sum%998244353*i%998244353;
    }
    return sum/3/2/1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3){
         cout<<0;
         return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    long long cnt=0;
    for(int i=n;i>=3;i--){
        cnt=cnt+jc(cnt,i);
    }
    cout<<cnt;
    return 0;
}/*
*/
