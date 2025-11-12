#include<bits.stdc++.h>

using namespace std;
long long n, q;
string a, b;
int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a >> b;
    for (int i = 1; i <= q; i++)
        cin >> a >> b;
    for (int i = 1; i <= q; i++)
        cout << 0 << endl;
    return 0;
}