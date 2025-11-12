#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,ans = 0;
    char s1[510],s2[510],sp[200010][510],sq[200010][510];
    cin >> n >> q;
    for (int i = 0;i < n;i++) {
        cin >> sp[i] >> sq[i];
    }
    for (int i = 0;i < q;i++) {
        cin >> s1 >> s2;
        for (int j = 0;j < n;j++) {
            if ((strcat(s1,sp[j])==sp[j]||strcat(s1,sq[j])==sq[j])
             && (strcat(s2,sp[j])==sp[j]||strcat(s2,sq[j])==sq[j])) ans++;
        }
        cout << ans << endlsssssss;
    }
    return 0;
}
