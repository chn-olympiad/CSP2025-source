#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+500;
int n ,q;
string S1[N], S2[N], T1[N], T2[N];

void init(){
    cin>> n>> q;
    for(int i=1; i<=n; i++) cin>> S1[i]>> S2[i];
    for(int i=1; i<=q; i++) cin>> T1[i]>> T2[i];
}
string C(string str, int L, int R){
    string S;
    S = str.substr(L,R);
    return S;
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    init();

    for(int i=1; i<=q; i++){
        string str1 = T1[i], str2 = T2[i];
        int L, R, len, ans=0, L1, L2;
        L1 = str1.size();

        for(int i=0; i<L1; i++){
            if(str1[i] != str2[i]){L = i;break;}}

        for(int i=L1; i>=0 ; i--){
            if(str1[i] != str2[i]){R = i;break;}}
        len = R-L+1;

        for(int k=1; k<=n; k++){
            L2 = S1[k].size();
            if(L2 < len) continue;
            if(L2 > L1)  continue;
            for(int j=L-L2 + len; j <= L; j++){
                if(j<0 || j+L2 > str1.size()) continue;
                string S = C(str1, j, L2);
                if(S != S1[k])  continue;
                string S_ = C(str2, j, L2);
                if(S_ != S2[k]) continue;
                ans++;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}
