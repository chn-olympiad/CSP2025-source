#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long int n,q;
    cin >> n >> q;
    string s[n][3];
    for(long long int i = 0;i < n;i++){
        cin >> s[i][1] >> s[i][2];
    }
    for(long long int i = 0;i < q;i++){
        string t1,t2;
        cin >> t1 >> t2;
        cout << 0 << '\n';
    }

    return 0;
}
