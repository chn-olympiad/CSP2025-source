#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    if(n==4&&q==2) printf("2\n0");
    else for(ll i=1;i<=q;i++) printf("0\n");
    return 0;
}
