#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct node{
    string a;
    string b;
    bool use;
}s[N];
int main(){
    freopen("rode.in","r",stdin);
    freopen("rode.out","w",stdout);
    int n , k;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> s[i].a >> s[i].b;
        s[i].use = false;
    }
    while(k--){
        string s1 , s2;
        cin >> s1 >> s2;
        bool check = true;
        for(int i = 1 ; i <= s1.size() ; i++){
            if(s1[i] != s2[i]){
                check = false;
                break;
            }
        }
        if(check){
            bool flag = false;
            for(int i = 1 ; i <= n ; i++){
                if(s[i].a == s1 && s[i].b == s2){
                    cout << 1;
                    return 0;
                }
            }
            if(!flag){
                cout << 0;
                return 0;
            }
        }
        int cnt = 0;
        for(int q = 0 ; q <= s1.size() ; q++){
            bool flag = true;
            int m ;
            for(int p = 1 ; p <= n ; p++){
                if(s[p].use)continue;
                if(s[p].a[0] == s1[q] && s[p].b[0] == s2[q]){
                    m = p;
                    s[p].use = true;
                    break;
                }
            }
            int i = 0;

            for(int p = q ; p < s1.size() && i < s[m].a.size() ; p++){
                s[p].use = true;
                if(!(s[m].a[i] == s1[p]) || !(s[m].b[i] == s2[p])){
                    flag = false;
                    break;
                }
                i++;
            }
            for(int p = m + s[m].a.size() ; p < s1.size() ; p++){
                s[p].use = true;
                if(s1[p] != s2[p]){
                    flag = false ;
                    break;
                }
            }
            if(flag){
                s[m].use = true;
                cnt++;
            }
        }
        cnt -= 1;
        cout << cnt << endl;
    }
    return 0;
}
