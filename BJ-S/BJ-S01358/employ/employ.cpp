#include <iostream>
using namespace std;

int c[505] = { };

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    long long int n,m,nn;
    string s;
    cin >> n >> m;
    cin >> s;
    nn = n;
    for(int i = 1; i <= n; i++){
        cin >>c[i];
        if(c[i] == 0)nn--;
    }
    long long int ans = 1;
    for(int i = nn; i >= abs(nn-m); i--){
        ans = ans * i;
    }
    cout << ans;
    return 0;
}
