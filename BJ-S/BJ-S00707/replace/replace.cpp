#include <bits/stdc++.h>
using namespace std;
int n,q,a[200005],b[200005],a2[200005],b2[200005];
string s1,s2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> s1 >> s2;
        for(int j = 0;j < s1.size();j++){
            if(s1[j] == 'b'){
                a[i] = j;
                b[i] = s1.size() - j - 1;
                break;
            }
        }
        for(int j = 0;j < s2.size();j++){
            if(s2[j] == 'b'){
                a2[i] = j;
                b2[i] = s2.size() - j - 1;
                break;
            }
        }
    }
    while(q--){
        cin >> s1 >> s2;
        int t1l,t1r,t2l,t2r,ans = 0;
        for(int i = 0;i < s1.size();i++){
            if(s1[i] == 'b'){
                t1l = i;
                t1r = s1.size() - i - 1;
                break;
            }
        }
        for(int i = 0;i < s2.size();i++){
            if(s2[i] == 'b'){
                t2l = i;
                t2r = s2.size() - i - 1;
                break;
            }
        }
        for(int i = 1;i <= n;i++){
            if(t1l >= a[i] && t1r >= b[i] && t1l - a[i] + a2[i] == t2l){
                if(t1r - b[i] + b2[i] == t2r) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
