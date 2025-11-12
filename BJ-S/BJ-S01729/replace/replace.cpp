#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
string s1[N],s2[N],t1[N],t2[N];
int n,q,ans;
void solve(){
    string a,b;
    cin >> a >> b;
    for(int i = 1;i <= n;i++){
        if(a.size() < max(s1[i].size(),s2[i].size()))
            continue;
        for(int j = 0;j <= a.size()-s1[i].size();j++){
            string aa = "",bb = "",cc = "";
            for(int k = 0;k < j;k++) aa += a[k];
            for(int k = j;k < j+s1[i].size();k++) bb += a[k];
            for(int k = j+s1[i].size();k < a.size();k++) cc += a[k];
            if(bb == s1[i])
                bb = s2[i];
            string ss = aa+bb+cc;
            if(ss == b)
                ans++;
            //cout << ss << " " << b << endl;
            //cout << bb << " " << s1[i] << endl;
        }
    }
    cout << ans << endl;
    ans = 0;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
        cin >> s1[i] >> s2[i];
    while(q--)
        solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
