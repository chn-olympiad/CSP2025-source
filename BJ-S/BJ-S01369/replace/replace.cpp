#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,q;
struct e{
    string l;
    string n;
    int len;
}b[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> b[i].l >> b[i].n;
        b[i].len = (b[i].l).size();
    }
    string s1,s2;
    while(q--){
        int ans = 0;
        cin >> s1 >> s2;
        int le = s1.size();
        for(int k=0;k<n;k++){
            if(s1 == b[k].l && s2 == b[k].l)
                ans++;
        }
        string s3 = s1;
        string s4 = s2;
        string s5;
        int j1 = 0,j2 = le;
        while(s1[j1] == s2[j1]){
            j1++;
        }
        while(s1[j2] == s2[j2]){
            j2--;
        }
        if(j1 == 0 && j2 == 0){
            cout << ans << endl;
            continue;
        }
        if(j1 == 0){
            bool flag;
            for(int i=le;i>=j2;i--){
                for(int k=0;k<n;k++){
                    flag = true;
                    for(int p=0;p<i;p++){
                        if(s1[p] != b[k].l[p] || s2[p] != b[k].l[p]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag)    ans++;
                }
            }
        }
        if(j2 == 0){
            bool flag;
            for(int i=0;i<=j1;i++){
                for(int k=0;k<n;k++){
                    flag = true;
                    for(int p=i;p<le;p++){
                        if(s1[p] != b[k].l[p] || s2[p] != b[k].l[p]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag)    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
