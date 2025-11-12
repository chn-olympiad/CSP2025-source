#include<bits/stdc++.h>
using namespace std;
string s1[200005];
string s2[200005];
int main(){
    freopen("replace.in", "r", stdin);
    freopne("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> s1[i] >> s2[i];
    while(q--){
        string a, b;
        cin>> a >> b;
        int ans = 0;
        if(a.size() != b.size())cout << 0 <<endl;
        for(int i = 0; i < a.size(); i++){
            bool flag1 = true;
            for (int j = 0; j < i; j++)if(a[j] != b[j])flag1 = false;
            if(flag1){
                for (int l = 0; l < a.size()-i; l++){
                    bool flag = true;
                    for (int j = i+l+1; j < a.size(); j++)if(a[j] != b[j])flag = false;
                    if(flag){
                        string c = "", d = "";
                        for (int j = i; j <= i+l; j++){
                            c+=a[j];
                            d+=b[j];
                        }
                        for (int j = 1; j <= n; j++)if(c ==s1[j] && d == s2[j])ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
