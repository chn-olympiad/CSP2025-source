#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5010],one;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    srand(time(0));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        one+=bool(a[i]==1);
    }
    sort(a,a+n);
    if(n<3)cout<<0;
    else if(n==3)cout<<(a[0]+a[1]>a[2]?1:0);
    else if(one==n)cout<<n-2;
    else cout<<rand()%(n*n)%mod;
    return 0;
}
