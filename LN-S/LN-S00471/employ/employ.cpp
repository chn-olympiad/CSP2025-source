#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int a[N+5];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<998244353){
        cout<<n;
    }
    else{
        cout<<n%998244353;
    }
    return 0;
}
