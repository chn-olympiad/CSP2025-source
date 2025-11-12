#include<bits/stdc++.h>
using namespace std;
int a[500];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=1;
    while(m--){
        sum*=n;
        n--;
    }
    cout<<sum%998244353;
    return 0;
}
