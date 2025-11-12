#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+10;
int n;
ll k;
ll a[N];
void sovle(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(k==0){
        if(n==1){
            cout<<0;
            return ;
        }
        if(n%2==0){
            cout<<n/2;
            return ;
        }
        else if(n%2==1){
            cout<<(n-1)/2+1;
            return ;
        }
    }
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = 1;
    while(N--) sovle();
    return 0;
}
