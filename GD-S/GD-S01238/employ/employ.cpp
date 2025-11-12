#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll maxn = 500+7,p=998'244'353;
ll n,m,a[maxn],ans=0;
string s;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    while(next_permutation(a+1,a+1+n)){
        ll no=0;
        for(ll i=1;i<=n;i++){
            if(no>=a[i]){
                continue;
            }
            if(s[i]=='0'){
                no++;
            }
        }
        if(n-no>=m)ans=(ans+1)%p;
    }
    cout<<ans<<"\n";
}