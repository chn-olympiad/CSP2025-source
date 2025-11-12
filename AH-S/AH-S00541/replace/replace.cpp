#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3+5;
int n, q, border[N][3][N], f[N][3][N];
string s[N][3], t[N][3];
inline ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
void Border(string s, int p, int q){
    int len = s.size();
    s = '#' + s;
    for(int i=2,j=0;i<=len;i++){
        while(j!=0 && s[j+1] != s[i])j = border[p][q][j];
//        cout <<"#" << i << ' ' << j << endl;
        j += (s[j+1] == s[i]);
        border[p][q][i] = j;
    }
//    for(int i=1;i<=len;i++)cout << border[p][q][i] << ' ';
//    cout << endl;/////
}
void Match(string t, string s, int p, int q){
    int len1 = t.size(), len2 = s.size();
    if(t < s)return;
    t = '#' + t;
    s = '#' + s;
    for(int i=1,j=0;i<=len1;i++){
        while(j!=0 && t[i] != s[j+1])j = border[p][q][j];
        j += (t[i] == s[j+1]);
//        cout << "# " << i << ' ' << j << endl;
        if(j == len2)f[p][q][i-j+1] = 1;
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n = read(), q = read();
    for(int i=1;i<=n;i++){
        cin >> s[i][1] >> s[i][2];
        Border(s[i][1], i, 1);
        Border(s[i][2], i, 2);
    }

    for(int i=1;i<=q;i++){
        int ans = 0;
        cin >> t[i][1] >> t[i][2];
        for(int l=1;l<=n;l++){
//            cout << "\n NOW " << i << ' ' << l << endl;
            Match(t[i][1], s[l][1], i, 1);
            Match(t[i][2], s[l][2], i, 2);
            for(int j=0;j<t[i][1].size();j++){
//                cout << "$ " << f[i][1][j+1] << ' ' << f[i][2][j+1] << endl;
                if(f[i][1][j+1] && f[i][2][j+1]){
                    bool flag = 1;
                    for(int o = 0;o<j;o++)if(t[i][1][o] != t[i][2][o])flag = 0;
                    for(int o = j+s[l][1].size();o<t[i][1].size();o++)if(t[i][1][o] != t[i][2][o])flag = 0;
                    if(flag){
                       ans++;
                    }
                }
                f[i][1][j+1] = f[i][2][j+1] = 0;
            }
//            cout << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/

