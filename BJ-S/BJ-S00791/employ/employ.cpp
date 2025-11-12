#include <iostream>
using namespace std;
const long long mod=998244353;
long long maybe(long long a){
    return (a==0?1:(a*maybe(a-1))%mod);
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int a;cin>>a;cout<<maybe(a);
    return 0;
}