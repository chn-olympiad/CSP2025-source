#include<iostream>
using namespace std;
const int MOD=998244353;
int n;
bool flag=true;
long long a[5005];
int f(long long pos, long long m, long long maxn, long long sum){
    if(pos==n+1){
        return m>=3&&sum>2*maxn;
    }
    return (f(pos+1,m,maxn,sum) + f(pos+1,m+1,max(maxn,a[pos]),sum+a[pos]))%MOD;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]!=1) flag=false;
    }
    if(flag==true){
        long long res=(1+n-2)*(n-2)/2;
        cout<<res<<endl;
    }else{
        cout<<f(1,0,-1,0)%MOD<<endl;
    }
    return 0;
}