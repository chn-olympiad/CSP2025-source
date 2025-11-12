//30
//30
//30
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005];
bool flag1 = 1,flag2 = 1;
void solve1(){
    if(k==0){
        cout<<n/2;
    }
    if(k==1) cout<<n;
    exit(0);
}

void solve2(){
    ll cnt = 0;
    for(ll i = 1;i<=n;i++)if(a[i]==1) cnt++;
    if(k==0){
        cout<<cnt/2+(n-cnt);
    }
    if(k==1){
        cout<<cnt;
    }
    exit(0);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(ll i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flag1 = 0;
        }
        if(a[i]!=1&&a[i]!=0) flag2 = 0;
    }
    if(flag1){
        solve1();
    }
    else if(flag2){
        solve2();
    }
    else{
        cout<<n;
    }
    return 0;
}
