#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
    return a>b;
}int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[1001]={},c=1;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)cin>>a[i];
    long long t=a[1],k=0;
    sort(a+1,a+n*m+1,cmp);
    for(long long i=1;i<=n*m;i++)if(a[i]==t)k=i;
    while(k>n){
        c++;
        k-=n;
    }if(c%2==1)cout<<c<<" "<<k;
    else cout<<c<<" "<<n-k+1;
    return 0;
}
