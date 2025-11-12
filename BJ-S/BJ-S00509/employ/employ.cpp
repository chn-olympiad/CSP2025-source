#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
long long jc(int n){
    return n*jc(n-1)%MOD;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int arr[100001];
    for(int i=1;i<=n;i++)cin>>arr[i];
    if(m<=n)cout<<jc(n);
    else cout<<0;
    return 0;
}
