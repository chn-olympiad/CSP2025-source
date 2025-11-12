#include <bits/stdc++.h>
using namespace std;
long long n,m,c[505],mod=998244353,a[100],ans;
long long fact(long long x){
    long long out=1;
    while(x){
        out*=(x--);
    }
    return out;
}
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    long long len=fact(n);
    for(int i=1;i<=len;i++){
        long long proresraw(0ll),tim(0ll);
        for(int j=1;j<=n;j++){
            if(s[j-1]=='0'||proresraw>=c[a[j]]){
                proresraw++;
            }
            else{
                tim++;
            }
        }
        if(tim>=m){
            ans++;
            ans%=mod;
        }
        next_permutation(a+1,a+n+1);
    }
    cout<<ans;
    return 0;
}