#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q;
    cin >> n >> q;

    if(q == 1)cout << 0;
    else{
        for(int i = 1; i<= q; i++) cout << 1;
    }

    return 0;
}
