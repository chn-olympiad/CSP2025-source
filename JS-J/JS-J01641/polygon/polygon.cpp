#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005],cnt;
int getmax(int p){
    int m=INT_MIN;
    for(int i=1;i<=p;i++){
        if(b[i]>m)m=b[i];
    }return m;
}
bool f(int p){
    int s=0;
    for(int i=1;i<=p;i++)s+=b[i];
    if(s>2*getmax(p))return 1;
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n=1)cout<<0;
    else if(n=2)cout<<0;
    else if(n=3 && a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1])cout<<1;
    else cout<<pow(2,n)%988244353;
    return 0;
}
