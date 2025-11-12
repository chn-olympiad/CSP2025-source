#include<bits/stdc++.h>
using namespace std;

int c(int n,int m){
    int n1=1;int n2=1;
    for(int i=n;i>n-m;i--) n1*=i;
    for(int i=m;i>=1;i--) n2*=i;
    return n1/n2;
}


int n;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*max({a[1],a[2],a[3]})) cout<<1;
        else cout<<0;
        return 0;
    }
    //12
    int sum=0;
    for(int i=3;i<=n;i++){
        sum+=c(n,i);
        sum%=998244353;
    }
    cout<<sum;
    //24
    return 0;
    //36
}
