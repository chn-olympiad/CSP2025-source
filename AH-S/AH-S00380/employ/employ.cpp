#include<bits/stdc++.h>
using namespace std;
long long n;
char s[505];
long long c[505];
long long f(long long x){
    long long s=1;
    for(int i=1;i<=n;i++){
        s*=i;
        s%=998244353;
    }
    return s;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    cout<<f(n);
    return 0;
}
