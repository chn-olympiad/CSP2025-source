#include<bits/stdc++.h>

using namespace std;

int n, q, ans;
string s1[200005], s2[200005];
string t1, t2;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> s1[i] >> s2[i];
    }
    while(q--){
        ans = 0;
        cin >> t1 >> t2;
        for(int i=0; i<t1.size(); i++){
            for(int j=i; j<t1.size(); j++){
                string t = t1.substr(i, j-i+1);
                string s = t2.substr(i, j-i+1);
                for(int k=1; k<=n; k++){
                    if(s1[k] == t && s2[k] == s){
                        //if(i == 0 && j == t1.size()-1){
                        //    ans ++;
                        //}else{
                            string x2 = t2.substr(0, i);
                            string z2 = t2.substr(j+1, t2.size()-j-1);
                            string T2 = x2+t+z2;
                            //cout << i << " " << j << endl;
                            //cout << x1 << " " << x2 << endl;
                            //cout << z1 << " " << z2 << endl;
                            //cout << T1 << " " << T2 << endl << endl;
                            if(t1 == T2){
                                ans ++ ;
                            }
                        //}
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
