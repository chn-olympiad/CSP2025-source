#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1, s2, x1, x2;
map <string,string> a;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> s1 >> s2;
        a[s1] = s2;
    }
    while (q--){
        int as = 0;
        cin >> x1 >> x2;
        int lx = x1.length();
        for (int i=0;i<lx;i++){
            for (int j=1;j<=lx-i;j++){
                string z = x1.substr(i,j);
                if (a[z]!=""){
                    string p = x1.substr(0,i)+a[x1.substr(i,j)]+x1.substr(i+j,lx-i-j+1);
                    if (p==x2) as++;
                }
            }
        }
        cout << as << endl;
    }
    return 0;
}
