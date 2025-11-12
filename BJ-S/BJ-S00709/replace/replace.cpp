#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
struct Hash{
    vector<int> pk;
    vector<int> a;
    int k,p;
    int n;
    void init(string s,int _k=37,int _p=1e9+7){
        k=_k;
        p=_p;
        a.clear();
        pk.clear();
        pk.emplace_back(1);
        a.emplace_back(0);
        n=s.length();
        for(int i=1;i<=n;i++){
            a.emplace_back((a[i-1]*k+s[i-1])%p);
            pk.emplace_back(pk[i-1]*k%p);
        }
    }
    int gethash(int L,int R){
        if(R<L){
            return 0;
        }
        return ((a[R]-a[L-1]*pk[R-L+1])%p+p)%p;
    }
}Hs1[200010],Hs2[200010],aft1[200010],aft2[200010];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin >> n >> t;
    map<pair<int,int>,multiset<pair<int,int> > > mp;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        Hs1[i].init(s,37,1e9+7);
        Hs2[i].init(s,101,1e9+9);
        cin >> s;
        aft1[i].init(s,37,1e9+7);
        aft2[i].init(s,101,1e9+9);
        mp[{Hs1[i].gethash(1,s.length()),Hs2[i].gethash(1,s.length())}].insert({aft1[i].gethash(1,s.length()),aft2[i].gethash(1,s.length())});
    }
    while(t--){
        string s1,s2;
        cin >> s1 >> s2;
        Hash tmps11,tmps12,tmps21,tmps22;
        tmps11.init(s1,37,1e9+7);
        tmps12.init(s1,101,1e9+9);
        tmps21.init(s2,37,1e9+7);
        tmps22.init(s2,101,1e9+9);
        int len=s1.length();
        int ans=0;
        for(int L=1;L<=len;L++){
            if(!(tmps11.gethash(1,L-1)==tmps21.gethash(1,L-1)&&tmps12.gethash(1,L-1)==tmps22.gethash(1,L-1))){
                continue;
            }
            for(int R=L;R<=len;R++){
                if(mp.find({tmps11.gethash(L,R),tmps12.gethash(L,R)})!=mp.end()&&tmps11.gethash(R+1,len)==tmps21.gethash(R+1,len)&&tmps12.gethash(R+1,len)==tmps22.gethash(R+1,len)){
                    ans+=mp[{tmps11.gethash(L,R),tmps12.gethash(L,R)}].count({tmps21.gethash(L,R),tmps22.gethash(L,R)});
                }
            }
        }
        cout << ans << endl;
        //cout.flush();
    }
    return 0;
}
