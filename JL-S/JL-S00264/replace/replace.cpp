#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ull base=13331;

int n,q;
ull pw[5000001],hs[5000001],h1[5000001];
map<int,unordered_map<ull,vector<int>>> mp;

inline ull get(ull *h,int l,int r){
    if (l>r) return 0;
    return h[r]-h[l-1]*pw[r-l+1];
}

inline ull meg(ull h1,ull h2,int l2){
    if (l2<=0) return h1;
    return h1*pw[l2]+h2;
}

inline ull geth(const string &s){
    ull h=0;
    for (auto i:s) h=h*base+i;
    return h;
}

inline void init(ull *h,const string &s,int n){
    h[0]=0;
    for (int i=1;i<=n;i++) h[i]=h[i-1]*base+s[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    pw[0]=1;
    for (int i=1;i<=5000000;i++) pw[i]=pw[i-1]*base;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        mp[s1.length()][geth(s1)].push_back(i);
        hs[i]=geth(s2);
    }
    while (q--){
        string s1,s2;
        cin>>s1>>s2;
        ull tar=geth(s2);
        int l1=s1.length();
        s1='_'+s1;
        init(h1,s1,l1);
        int cnt=0;
        for (auto &[len,m]:mp){
            if (len>l1) break;
            for (int i=1;i+len-1<=l1;i++){
                auto it=m.find(get(h1,i,i+len-1));
                if (it!=m.end()){
                    for (auto j:it->second){
                        if (meg(meg(get(h1,1,i-1),hs[j],len),get(h1,i+len,l1),l1-i-len+1)==tar) cnt++;
                    }
                }
            }
        }
        cout<<cnt<<"\n";
    }
	return 0;
}