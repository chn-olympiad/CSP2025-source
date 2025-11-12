#include <iostream>
using namespace std;
long long j(long long a,long long b){
    long long re=1;
    for(long long i=a-b+1;i<=a;i++){
        re*=i;
        re=re%998244353;
    }
    return re%998244353;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    if(a==b){
        cout<<j(b,b);
        return 0;
    }
    else{
        cout<<j(a,a);
    }

    return 0;
}

