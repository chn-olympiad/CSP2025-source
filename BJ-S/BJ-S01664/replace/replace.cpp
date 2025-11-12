#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

string s1[N], s2[N];
int h[N], d[N];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n, Q; cin >> n >> Q;
    for(int i=1; i<=n; i++){
        cin >> s1[i] >> s2[i];
        for(int j=0; j<s1[i].length(); j++)
            if(s1[i][j] == 'b'){
                h[i] = j;
                break;
            }
        for(int j=0; j<s2[i].length(); j++)
            if(s2[i][j] == 'b'){
                // How much did 'b' go right
                d[i] = j - h[i];
                break;
            }
    }

    while(Q--){
        string t1, t2; cin >> t1 >> t2;
        if(t1.length() != t2.length()){
            cout << "0\n";
            continue;
        }

        int p1, p2;
        for(int i=0; i<t1.length(); i++)
            if(t1[i] == 'b'){
                p1 = i;
                break;
            }
        for(int i=0; i<t2.length(); i++)
            if(t2[i] == 'b'){
                p2 = i - p1;
                break;
            }

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(h[i] > p1) continue;
            int srem = s1[i].length() - h[i],
                trem = t1.length() - p1;
            if(srem > trem) continue;

            if(d[i] == p2) ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
