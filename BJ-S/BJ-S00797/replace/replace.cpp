#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
string s[N][2],t[N][2];
int findb(string a){
    int cnt = 0;
    for(int i = 0;i < a.length();i ++){
        if(a[i] == 'b') return i;
    }
    return 0;
}
int findsame(string s,string t,int l,int r){
    for(int ql = 0;ql < s.length();ql ++){
        bool flag = true;
        int cnt = ql;
        for(int i = l;i <= r;i ++){
            if(t[i] != s[cnt]) flag = false;
            cnt ++;
        }
        if(flag) return ql;
    }
    return -1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i = 0;i < n;i ++) cin >> s[i][0] >> s[i][1];
    for(int i = 0;i < q;i ++) cin >> t[i][0] >> t[i][1];
    if(q == 1){
        int l = 0,r = 0;
        bool flag = true;
        for(int i = 0;i < t[0][0].length();i ++){
            if(t[0][0][i] != t[0][1][i]){
                if(flag){
                    l = i;
                    flag = false;
                }else{
                    r = i;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i ++){
            if(s[i][0].length() == (r - l + 1)){
                bool flag = true;
                int cnt = 0;
                for(int j = l;j <= r;j ++){
                    if(s[i][0][cnt] != t[0][0][j] || s[i][1][cnt] != t[0][1][j]) flag = false;
                    cnt ++;
                }
                if(flag) ans ++;
            }else{
                int ql = findsame(s[i][0],t[0][0],l,r);
                int qr = ql + (r - l);
                if(ql == -1) continue;
                bool flag1 = true,flag2 = true;
                int checkl = l,checkr = r;
                for(int j = ql;j >= 0;j --){
                    if(s[i][0][j] != t[0][0][checkl]) flag1 = false;
                    checkl --;
                }
                if(!flag1) continue;
                for(int j = qr;j < s[i][0].length();j ++){
                    if(s[i][0][j] != t[0][0][checkr]) flag2 = false;
                    checkr ++;
                }
                checkl ++;
                checkr --;
                if(flag1 && flag2){
                    bool final_flag = true;
                    for(int j = checkl;j <= checkr;j ++){
                        if(s[i][1][j] != t[0][1][j]) final_flag = false;
                    }
                    if(final_flag) ans ++;
                }
            }
        }
        cout << ans;
        return 0;
    }
    for(int i = 0;i < q;i ++){
        int cnt = 0;
        int b1 = findb(t[i][0]),b2 = findb(t[i][1]);
        for(int j = 0;j < n;j ++){
            int b3 = findb(s[j][0]),b4 = findb(s[j][1]);
            if(s[j][0].length() <= t[i][0].length()){
                if(b1 - b3 > 0){
                    if(s[j][0].length() + b1 - b3 < t[i][0].length()){
                        if(b1 - b3 == b2 - b4) cnt ++;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
