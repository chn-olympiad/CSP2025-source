#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long n,a[5010],sum,ans;
long long C(long long m,long long n){
    long long res=1;
    for(int i=1;i<=m;i++){
        if(i!=n) res=res*n/i%N;
        n--;
    }
    return res;
    }
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(n<3){
        cout<<0<<endl;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]>a[3])
            cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    else if(a[n]==1){
        for(int i=3;i<=n;i++){
            sum+=C(i,n)%N;
        }
        cout<<sum<<endl;
    }
    else{
        cout<<n*2<<endl;
    }
    return 0;
}

