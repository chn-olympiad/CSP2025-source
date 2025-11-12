#include<bits/stdc++.h>
using namespace std;
string s[200005][2];
string a,b,c;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 0;i<n;i++){
        cin >> s[i][0] >> s[i][1];
    }
    while(q--){
        cin >> c >> b;
        a = c;
        int p = 0;
        for(int i = 0;i<n;i++){
            a = c;
            for(int j = 0;j<a.size();j++){
                if(a[j] == s[i][0][0]){
                    int flag = 1;
                    for(int k = 0;k<s[i][0].size();k++){
                        if(a[j+k]!=s[i][0][k]){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag){
                        for(int k = 0;k<s[i][0].size();k++){
                            a[j+k] = s[i][1][k];
                        }
                        break;
                    }
                }
            }
            if(a == b){
                p++;
            }
        }
        cout << p << endl;
    }
    return 0;
}

