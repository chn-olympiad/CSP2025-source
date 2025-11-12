#include <bits/stdc++.h>
using namespace std;
int n, q;
const int N = 200005;
struct str2{
    string s1;
    string s2;
}s[N];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        string temp1 = "", temp2 = "";
        cin>>s[i].s1>>s[i].s2;
        int len = s[i].s1.length();
        for(int k = 0;k<len;k++){
            if(s[i].s1[k] != s[i].s2[k]) temp1 += s[i].s1[k], temp2 += s[i].s2[k];
        }
        s[i].s1 = temp1;
        s[i].s2 = temp2;
    }
    for(int i = 1;i<=q;i++){
        int ans = 0;
        string t1, t2;
        string nt1 = "", nt2 = "";
        int flag = 0;
        cin>>t1>>t2;
        int len = t1.length();
        if(len != t2.length()) flag = 2;
        for(int k = 0;k<len;k++){
            if(flag == 2){
                cout<<0<<endl;
                break;
            }
            if(t1[k] != t2[k]) nt1 += t1[k], nt2 += t2[k];
            if(k == 0){
                if(t1[k] != t2[k]) flag++;
            }
            else if(t1[k] != t2[k] && t1[k-1] == t2[k-1]) flag++;
        }
        if(flag == 2) continue;
        for(int k = 1;k<=n;k++){
            string s1 = s[k].s1;
            string s2 = s[k].s2;
            if(s1 == nt1 && s2 == nt2) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
