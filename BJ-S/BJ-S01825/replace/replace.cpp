#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,q;
map<string,string> mp;
//map<int,int> cn;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        string x,y;
        cin >> x >> y;
        mp[x] = y;
//        int a = x.size(),b = y.size();
//        cn[a-b]++;
    }
    int tmpq = q;
    while(q--){
        string s,t;
        cin >> s >> t;
//        if(n>1e3){
//            int a = s.size(),b = t.size();
//            cout << cn[b-a] << endl;
//            continue;
//        }
        int ans = 0;
        for(int l=0;l<s.size();l++){
            string tmp = "";
            for(int r=l;r<s.size();r++){
                tmp+=s[r];
                if(mp.count(tmp)){
                    string tmp3 = "";
                    if(l>0){
                        tmp3+=s.substr(0,l);
                    }
                    tmp3+=mp[tmp];
                    if(r+1<s.size()){
                        tmp3+=s.substr(r+1);
                    }
//                    cout << l << " " << r << " " << tmp3 << endl;
                    if(tmp3==t){
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
