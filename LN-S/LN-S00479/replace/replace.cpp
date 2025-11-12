
#include <bits/stdc++.h>
using namespace std;
map <string, string> mp;
int N, Q;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> N >> Q;
    while(N --) {
        string s1, s2;
        cin >> s1 >> s2;
        //if(mp[s1] == s2) cout << 666;
        mp[s1] = s2;
    }
    while(Q--) {
        long long ans = 0;
        string t1, t2;
        cin >> t1 >> t2;
        string use1 = "";
        string use2 = "";
        int len = t1.size();
        int same_left = 0;
        int same_right = 0;
        for(int i=0;i<len;i++) {
            if(t1[i] == t2[i]) same_left ++;
            else break;
        }
        for(int i=len-1;i>=0;i--) {
            if(t1[i] == t2[i]) same_right ++;
            else break;
        }
        for(int i=same_left;i<len-same_right;i++) {
            use1 += t1[i];
            use2 += t2[i];
        }
        if(mp[use1] == use2) ans += 1;
        for(int i=1;i<=min(same_left, same_right);i++) {

            if(mp[use1+t1[len-same_right+i-1]] == use2+t2[len-same_right+i-1]) ans += 1;
            if(mp[t1[same_left-i]+use1] == t2[same_left-i]+use2) ans += 1;
            use1 = t1[same_left-i]+use1+t1[len-same_right+i-1];
            use2 = t2[same_left-i]+use2+t2[len-same_right+i-1];
            if(mp[use1] == use2) ans += 1;
            //cout << use1 << " " << use2 << endl;
        }
        if(same_right > same_left) {
            for(int i=1;i<=same_right-same_left;i++) {
                use1 = use1+t1[len-same_right+same_left+i-1];
                use2 = use2+t2[len-same_right+same_left+i-1];
                if(mp[use1] == use2) ans += 1;
                //cout << use1 << " " << use2 << endl;
            }
        }else if(same_left > same_right) {
            for(int i=1;i<=same_left-same_right;i++) {
                use1 = t1[same_left-same_right-i]+use1;
                use2 = t2[same_left-same_right-i]+use2;
                if(mp[use1] == use2) ans += 1;
                //cout << use1 << " " << use2 << endl;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
