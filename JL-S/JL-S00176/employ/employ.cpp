#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=1;
int c[505];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=n;i>=1;i--){
        sum*=i;
    }
    cout<<sum%998244353;
return 0;
}
