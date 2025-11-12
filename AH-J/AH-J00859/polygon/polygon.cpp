#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int f[5005][5005];
int MOD=998244353;
int A(int x,int y){
    int sum=1;
    while(y--){
        sum*=x;
        x--;
        sum%=MOD;
    }
    return sum%MOD;
}
int C(int x,int y){
    return (A(x,y)%MOD)/(A(y,y)%MOD);
}
int work1(int x){
    if(x==0){
        return 1;
    }
    return (C(n,x)%MOD+work1(x-1)%MOD)%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        cout<<(a[1]+a[2]>a[3]);
        return 0;
    }
    if(a[n]==1){
        int i;
        for(i=n;i>=1&&a[i];i--);
        cout<<work1(n-i-3)%MOD;
    }
    return 0;
}
