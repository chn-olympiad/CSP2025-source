#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const long long M=998244353;
int n;
int a[N];
bool cf(){
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            return false;
        }
    }
    return true;
}
long long qpow(long long a,long long n){
    int res=1;
    while(n>0){
        if(n%2==1)res=(res*a)%M;
        a=(a*a)%M;
        n/=2;
    }
    return res;
}
void f(){
    cout<<(qpow(2,n)-(1+n+(n*(n-1)/2)%M)%M+M)%M;
}
long long ans=0;
int mm=0;
int m[N];
void blf(int num,int maxx,int sum,int sidx){
    if(num>=3){
        if(sum>2*mm){
            ans=(ans+qpow(2,n-sidx));
            return ;
        }else if(sum>2*maxx&&sum>2*m[sidx+1]){
            ans=(ans+qpow(2,n-sidx));
            //cout<<111<<endl;
            return ;
        }else if(sum>maxx*2){
            ans=(ans+1)%M;
        }
    }
    for(int i=sidx+1;i<=n;i++){
        blf(num+1,max(a[i],maxx),sum+a[i],i);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(cf())f();
    else{
        for(int i=1;i<=n;i++){
            mm=max(a[i],mm);
        }
        for(int i=n;i>=1;i--){
            m[i]=max(a[i],m[i+1]);
        }
        blf(0,0,0,0);
        cout<<ans;
    }
    return 0;
}
