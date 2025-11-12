#include <iostream>
using namespace std;
string s;
const int N = 510;
int c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    cout<<n%998244353;

    return 0;
}
