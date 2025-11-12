#include<bits/stdc++.h>
using namespace std;
const long long q=998244353;
long long n,m,k,sum;
string s;
long long happy(long long x){
    if(x==1||x==0){
        return 1;
    }
    else return x*happy(x-1)%q;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;

    cout<<happy(n)%q;
    return 0;
}
