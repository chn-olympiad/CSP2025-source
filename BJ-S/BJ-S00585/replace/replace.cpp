

#include <bits/stdc++.h>

using namespace std;

int n, q;
string s1, s2;

struct node {
    string x;
    string y;
};
node s[1000009];
int cha[1000009];
int we1[1000009];
int we2[1000009];

bool pd (string S) {
    int ta = 0;
    int tb = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i]=='a') {
            ta++;
        }
        if (S[i]=='b') {
            tb++;
        }
    }
    if (ta+tb==S.length()) {
        return true;
    }
    return false;
}

void make (int X) {
    for (int i = 0; i < s[X].x.length(); i++) {
        if (s[X].x[i] == 'b') {
            we1[X] = i;
        }
        if (s[X].y[i] == 'b') {
            we2[X] = i;
        }
    }

    cha[X] = we1[X]-we2[X];
}

void checkb () {
    int thei, thej;
    long long ans = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i]=='b') {
            thei = i;
        }
        if (s2[i]=='b') {
            thej = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (thei-thej!=cha[i]) {
            continue;
        }
        if (thei-1>=we1[i]-1&&s1.length()-thei>=s[i].x.length()-we1[i]) {
            if (thej-1>=we2[i]-1&&s2.length()-thej>=s[i].y.length()-we2[i]) {
                ans++;
            }
        }
    }
    cout << ans << endl;

}

void init () {
    for (int i = 1; i <= n+2; i++) {
        cha[i] = 0;
        we1[i] = 0;
        we2[i] = 0;
    }
}

bool pd2 (int X, int Y, int Z) {
    for (int i = 0; i < s[X].x.length()-(Z-Y+1); i++) {
        int cc = 0;
        if (s[X].x[i]==s1[Y]) {
            int f = 1;
            for (int j = Y; j <= Z; j++) {
                if (s[X].x[i+cc]!=s1[j]) {
                    f = 0;
                    break;
                }
                cc++;
            }
            if (f == 1) {
                int ccc = 0;
                for (int k = Y; k <= Z; k++) {
                    if (s[X].y[i+ccc]!=s2[k]) {
                        f = 0;
                        break;
                    }
                }
                if (f==1) {
                    return true;
                }
            }
        }
    }
    return false;
}

void checko () {
    int thei, thej;
    long long sum = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i]!=s2[i]) {
            thei = i;
            break;
        }
    }
    for (int i = s1.length()-1; i >= 0; i--) {
        if (s1[i]!=s2[i]) {
            thej = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i].x.length()<thej-thei+1) {
            continue;
        }
        if (pd2(i, thei, thej)) {
            sum++;
        }
    }
    cout << sum << endl;
}

int main () {

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int f = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].x >> s[i].y;
    }
    if (pd(s[1].x)&&pd(s[1].y)&&pd(s[2].x)&&pd(s[2].y)) {
        for (int i = 1; i <= n; i++) {
            make(i);
        }
        f = 1;
    }
    while (q--) {
        init();
        cin >> s1 >> s2;
        if (s1.length()!=s2.length()) {
            cout << 0 << endl;
            continue;
        }
        if (f==1) {
            checkb();
        }
        else {
            checko();
        }
    }

    return 0;
}
