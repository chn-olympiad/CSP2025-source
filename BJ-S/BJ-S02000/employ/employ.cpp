#include<iostream>
#include<string>
using namespace std;
int n,m,c[550];
long long ans = 1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i = 1;i <= n;i++){
        cin>>c[i];
        ans *= i;
    }
    cout<<ans % 998244353;
    return 0;
}
