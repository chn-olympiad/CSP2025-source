#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#define int long long
using namespace std;

int n,q;
vector<pair<string,string>> vec;
string a,b;

struct AB {
    int a;
    int b;
};

vector<pair<AB,AB>> cev;

signed main() 
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0) -> sync_with_stdio(false);
    
    cin >> n >> q;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        vec.push_back(make_pair(a,b));
        int aa = a.find('b');
        int bb = b.find('b');
        cev.push_back(make_pair((AB){aa,(int)a.size()-aa-1},(AB){bb,(int)b.size()-bb-1}));
    }
    for(int i=0;i<q;i++) {
        cin >> a >> b;
        if(n <= 100 && q <= 100) {
            a += ' ', b += ' ';
            int ans = 0;
            for(auto j:vec) {
                string sa = j.first;
                string sb = j.second;
                int pos = a.find(sa);
                if(pos == string::npos) continue;
                string ta = a.substr(0,pos)+sb+a.substr(pos+sb.size());
                if(ta == b) ans++;
            } cout << ans << endl;
        } else {
            int aa = a.find('b');
            int bb = b.find('b');
            int ans = 0;
            for(auto j:cev) {
                if(aa >= j.first.a && (int)a.size()-aa-1 >= j.first.b) {
                    aa = aa - j.first.a + j.second.a;
                    if(aa == bb) ans++;
                    aa = aa + j.first.a - j.second.a;
                }
            } cout << ans << endl;
        }
    }
    return 0;
}