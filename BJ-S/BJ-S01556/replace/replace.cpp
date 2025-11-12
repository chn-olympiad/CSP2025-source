#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,q;
string s[N][2];
string t0,t1;
void solve1(){
    while(q--){
        cin >> t0 >> t1;
        if(t0.size() != t1.size()){
            printf("0\n");
            continue;
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j+s[i][0].size() <= t0.size();j++){
                bool flag = false;
                for(int k=j;k<j+s[i][0].size();k++){
                    if(t0[k] != s[i][0][k-j]){
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    continue;
                string p = t0;
                for(int k=j;k<j+s[i][0].size();k++)
                    p[k] = s[i][1][k-j];
                if(p == t1){
                    ans++;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for(int i=1;i<=n;i++)
        cin >> s[i][0] >> s[i][1];
    if(n <= 100)
        solve1();
    else
        solve1();
    return 0;
}
