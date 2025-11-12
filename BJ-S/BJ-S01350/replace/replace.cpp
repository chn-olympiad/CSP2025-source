#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using std::cin;
using std::cout;
using std::string;
using std::map;
using std::vector;
using std::pair;
//#define DEBUG
#define freopen(...)
#ifdef DEBUG
#define debug printf
#else
#define debug(...)
#endif // DEBUG
string substr(string s, int st, int ed=-1) {
    if(ed<0) ed = s.size();
    //if(st<0) st = s.size() + st;
    return s.substr(st, ed-st);
}
struct Replace {
    string a, b, pre, nxt;
    Replace(string a, string b) {
        int st=0, ed=a.size()-1;
        while(a[st]==b[st]) st++;
        while(a[ed]==b[ed]) ed--;
        // debug("%s&%s: %d ~ %d\n", a.c_str(), b.c_str(), st, ed);
        this->a = substr(a,st,ed+1);
        this->b = substr(b,st,ed+1);
        this->pre = substr(a, 0,st);
        this->nxt = substr(a, ed+1);
    }
    string dbg() const {
        return pre+"("+a+"->"+b+")"+nxt;
    }
};
int main() {
    freopen("data.in", "r", stdin);
    int n, q;
    cin >> n >> q;
    map<pair<string,string>, vector<Replace> > mp;
    for(int i=0; i<n; i++) {
        string a, b;
        cin >> a >> b;
        const Replace r(a,b);
        debug("%s\n", r.dbg().c_str());
        const decltype(mp)::key_type k(r.a,r.b);
        mp[k].push_back(r);
    }
    for(int i=0; i<q; i++) {
        string a, b;
        cin >> a >> b;
        const Replace diff(a,b);
        const decltype(mp)::key_type k(diff.a,diff.b);
        int cnt = 0;
        debug("%s: \n", diff.dbg().c_str());
        for(const Replace &r : mp[k]) {
            if(r.pre != substr(diff.pre, diff.pre.size()-r.pre.size())) continue;
            if(r.nxt != substr(diff.nxt, 0, r.nxt.size())) continue;
            cnt++;
            debug("  %d: %s\n", cnt, r.dbg().c_str());
        }
        cout << cnt << "\n";
    }
    return 0;
}
