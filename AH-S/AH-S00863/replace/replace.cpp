#include <bits/stdc++.h>
using namespace std;

bool is_sp(string a,string b)
{
    int l1=a.length(),l2=b.length();
    if (l1-l2 == 1) {
        return false;
    }
    for (int i=0;i<a.length();i++) {
        if (i < l2 && a[i] != b[i]) {
            return true;
        }
    }
    return false;
}

bool is_zc(string t1,string str)
{
    int k=1;
    int n2=t1.length();
    n2*=(n2+1);
    n2/=2;
    string zc1[n2+1]={""};
    for (int i=0;i<t1.length();i++) {
        for (int j=i;j<t1.length();j++) {
            if (j != i) {
                zc1[k] += zc1[k-1];
                zc1[k] += t1[j];
            } else {
                zc1[k] = t1[j];
            }
            k++;
        }
    }
    for (int i=0;i<n2+1;i++) {
        if (zc1[i] == str) {
            return true;
        }
    }
    return false;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    string str[n][2];
    for (int i=0;i<n;i++) {
        cin >> str[i][0] >> str[i][1];
    }
    while (q--) {
        string t1,t2;
        cin >> t1 >> t2;
        int cnt=0;
        if (t1.length() != t2.length()) {
            cout << 0 << endl;
            continue;
        }
        for (int i=0;i<n;i++) {
            string x="",y="",z="";
            string s2=str[i][0];
            if (is_zc(t1,s2)) {
                y=str[i][1];
                int l=y.length(),l1=t1.length(),l2=t2.length();
                if (is_zc(t2,y)) {
                    if (!(y[0] == t2[0] && y[l-1] != t2[l2-1]) || !(y[0] != t2[0] && y[l-1] == t2[l2-1])) {
                        if (is_sp(t2,y)) {
                            cnt++;
                        }
                    }
                }
            } else {
                continue;
            }
        }
        cout << cnt << endl;

    }
}
