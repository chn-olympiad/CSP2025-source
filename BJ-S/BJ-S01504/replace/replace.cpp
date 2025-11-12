#include<bits/stdc++.h>
using namespace std;using LL=int64_t;using LD=long double;
#define f(i,a,b) for(int i=(a),E##i=(b);i<=E##i;++i)
#define fr(i,a,b) for(int i=(a),E##i=(b);i>=E##i;--i)
#define fu(i,a,b) for(int i=(a),E##i=(b);i<E##i;++i)
#define endl '\n'
auto freo(string s){
    string in=s+".in";
    string out=s+".out";
    return make_pair(
        freopen(in.c_str(),"r",stdin),
        freopen(out.c_str(),"w",stdout)
    );
}
using strhash_t=unsigned long long;
constexpr strhash_t B=1e9+9,L=5e6+5;
strhash_t pwB[L];
strhash_t strhash(string s){
    strhash_t res=0;
    for(char ch:s)res=res*B+ch;
    return res;
}
struct pair_set{
    using pair_t=pair<strhash_t,strhash_t>;
    vector<pair_t>a;
    void add(pair_t val){
        a.push_back(val);
    }
    void prepare(){
        sort(a.begin(),a.end());
    }
    int query(pair_t val){
        auto itl=lower_bound(a.begin(),a.end(),val);
        auto itr=upper_bound(a.begin(),a.end(),val);
        return itr-itl;
    }
}pset;
int main(){
    freo("replace");
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pwB[0]=1;fu(i,1,L)pwB[i]=pwB[i-1]*B;
    int n,q;cin>>n>>q;
    while(n--){
        string s1,s2;cin>>s1>>s2;
        strhash_t h1=strhash(s1);
        strhash_t h2=strhash(s2);
        pset.add(make_pair(h1,h2));
    }
    pset.prepare();
    while(q--){
        string t1,t2;cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        int diffl=0;
        while(t1[diffl]==t2[diffl])++diffl;
        int diffr=t1.size()-1;
        while(t1[diffr]==t2[diffr])--diffr;
        int len=diffr-diffl+1,mlen=len;
        strhash_t sh1=strhash(t1.substr(diffl,diffr-diffl+1));
        strhash_t sh2=strhash(t2.substr(diffl,diffr-diffl+1));
        int ans=0;
        fr(l,diffl,0){
            if(l!=diffl){
                sh1+=t1[l]*pwB[mlen];
                sh2+=t2[l]*pwB[mlen];
                ++mlen;
            }
            strhash_t h1=sh1,h2=sh2;
            fu(r,diffr,t1.size()){
                if(r!=diffr){
                    h1=h1*B+t1[r];
                    h2=h2*B+t2[r];
                }
                ans+=pset.query(make_pair(h1,h2));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//pass sample 1,2:17:11