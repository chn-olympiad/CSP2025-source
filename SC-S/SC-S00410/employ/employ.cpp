#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,a[505]={};
    string s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long x=1;
    for(int i=1;i<=n;i++){
        x*=i;
        x%=998244353;
    }
    cout<<x;
    return 0;
}
