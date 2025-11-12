#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3],s1,s2;
int findx(string a,string b){
    int len=0,h=0x3f3f3f3f;
    int t=-1,lb=0;
    for (int i=0;i<a.size();i++){
        if (a[i]==b[lb]){
            h=min(h,i);
            len++,lb++;
            if (len==b.size()){
                t=h;
                break;
            }
        }
        else len=0,h=0x3f3f3f3f,lb=0;
    }
    return t;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    bool tf=1;
    for (int i=1;i<=n;i++){
        cin >> s[i][1] >> s[i][2];
    }
    while(q--){
        cin >> s1 >> s2;
        int ans=0;
        if (s1.size()!=s2.size()){
            cout << 0 << "\n";
            continue;
        }
        for (int i=1;i<=n;i++){
            string x=s1;
            int a=findx(x,s[i][1]);
            if (a!=-1){
                for (int j=a;j<=a+s[i][1].size()-1;j++){
                    x[j]=s[i][2][j-a];
                }
                if (x==s2) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
