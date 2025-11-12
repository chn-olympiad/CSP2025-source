#include<bits/stdc++.h>
#define int long long
using namespace std;
const int B=100,mod=998244353;
int n,q;
map<tuple<int,int,int>,int> mp;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        string s1,s2;
        cin >> s1 >> s2;
        int x=0,y=0,len=s1.size();
        for (int j=0;j<len; j++) {
            x=(x*B+s1[j]-'a')%mod;
        }
        for (int j=0; j<len; j++) {
            y=(y*B+s2[j]-'a')%mod;
        }
        mp[{x,y,len}]++;
    }
    while (q--) {
        string s1,s2;
        cin >> s1 >> s2;
        int l,r;
        for (l=0; l<s1.size(); l++) {
            if (s1[l]!=s2[l]) {
                break;
            }
        }
        for (r=s1.size()-1; r>=0; r--){
            if (s1[r]!=s2[r]) {
                break;
            }
        }
        //cout << l << " " << r << "\n";
        int ans=0;
        for (int i=0; i<=l; i++) {
            for (int j=i,x=0,y=0; j<s1.size(); j++) {
                x=(x*B+s1[j]-'a')%mod;
                y=(y*B+s2[j]-'a')%mod;
                if (j>=r) {
                    //cout << i << " " << j << "\n";
                    ans+=mp[{x,y,j-i+1}];
                }
            }
        }
        cout << ans << "\n";
    }
	return 0;
}
