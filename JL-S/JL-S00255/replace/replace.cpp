#include<bits/stdc++.h>
#define st first
#define nd second

using namespace std;
int n,q;
typedef pair<string,string> pss;
map<pss,vector<pss>> ms;
pair<pss,pss> getsd(string l,string r){
    l = "@"+l+"#";
    r = "@"+r+"#";
    int il=0,ir=l.size()-1;
    while(l[il+1] == r[il+1])il++;
    while(l[ir-1] == r[ir-1])ir--;
    return make_pair(
        make_pair(l.substr(il+1,ir-il-1),
                  r.substr(il+1,ir-il-1)),
        make_pair(l.substr(0,il+1),
                  l.substr(ir,string::npos))
    );
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string l,r;
        cin>>l>>r;
        if(l==r)continue;
        pair<pss,pss> pps = getsd(l,r);
        ms[pps.st].push_back(pps.nd);
    }
    for(int i=0;i<q;i++){
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        pair<pss,pss> pps = getsd(t1,t2);
        if(ms.find(pps.st) == ms.end()){
            cout<<0<<endl;
            continue;
        }
        int ans = 0;
        vector<pss>& vp = ms[pps.st];
        for(pss pi : vp){
            if(pi.st.size() > pps.nd.st.size()
             ||pi.nd.size() > pps.nd.nd.size())
                continue;
            int fl = 0;
            for(int i=0;i<pi.st.size()-1;i++){
                if(pps.nd.st[pps.nd.st.size()-1-i] != pi.st[pi.st.size()-1-i]){
                    fl=1;break;
                }
            }
            if(fl)continue;
            for(int i=0;i<pi.nd.size()-1;i++){
                if(pps.nd.nd[i] != pi.nd[i]){
                    fl=1;break;
                }
            }
            if(fl)continue;
            ans++;
        }
        cout<<ans<<endl;
    }
}
