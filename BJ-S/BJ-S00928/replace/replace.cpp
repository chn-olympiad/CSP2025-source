#include <iostream>
#include <cstring>
using namespace std;

int n, q, s[200005];
bool is[200005];
char a1[200005][105];
char a2[200005][105];
char t1[200005][105];
char t2[200005][105];

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> a1[i] >> a2[i];
        s[i] = strlen(a1[i]);
    }
    for(int j=1; j<=q; j++){
        cin >> t1[j] >> t2[j];
        int l = strlen(t1[j]), lt=0, rt=l-1, ans=0;
        for(int i=0; i<l; i++){
            is[i] = (t1[j][i] == t2[j][i]);
        }
        while(is[lt] == 1) lt++;
        while(is[rt] == 1) rt--;
        int p = rt-lt+1;
        for(int i=1; i<=n; i++){
            if(p <= s[i]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
