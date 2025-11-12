#include<bits/stdc++.h>
using namespace std;

int n, q;
string s[200005][2];
string t[200005][2];

bool str_in(string a, string b){
    int len_a = a.length();
    int len_b = b.length();
    for(int i=0; i<=len_b-len_a; i++){
        if(b.substr(i, len_a).compare(a)==0) return 1;
    }
    return 0;
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1; i<=q; i++){
        cin>>t[i][0]>>s[i][1];
    }
    for(int i=1; i<=q; i++){//t
        int ans = 0;
        for(int j=1; j<=n; j++){//s
            if(str_in(t[j][0], s[i][0])){
                if(s[i][0].replace(s[i][0].find(t[j][0]), t[j][1].length(), t[j][1], 1).compare(s[i][1])==0){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
