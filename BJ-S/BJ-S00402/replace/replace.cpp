#include <bits/stdc++.h>
using namespace std;
const int B=29,L=5e6+5;
struct trie{
    struct node{int cnt,ch[26];};
    node z;
    vector<node> tr;
    inline void insert(string s){
        if(tr.empty()) tr.push_back(z);
        int p(0);
        for(int i(0);i<s.length();++i){
            if(!tr[p].ch[s[i]-'a']) tr.push_back(z),tr[p].ch[s[i]-'a']=tr.size()-1;
            p=tr[p].ch[s[i]-'a'];
        }
        ++tr[p].cnt;
    }
    inline int ans(string s){
        if(tr.empty()) return 0;
        int p(0),res(tr[0].cnt);
        for(int i(0);i<s.length();++i){
            if(!tr[p].ch[s[i]-'a']) return res;
            p=tr[p].ch[s[i]-'a'],res+=tr[p].cnt;
        }
        return res;
    }
};
int n,q,ans;
string s1,s2,u;
unsigned long long mem;
unordered_map<unsigned long long,trie> mp;
inline void file(){freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> n >> q;
    for(int i(1),fir,las;i<=n;++i){
        cin >> s1 >> s2,fir=s1.length(),las=-1,mem=0,u.clear();
        for(int j(0);j<s1.length();++j) if(s1[j]!=s2[j]) fir=min(fir,j),las=max(las,j);
        for(int j(fir);j<=las;++j) mem*=B,mem+=(s1[j]-'a'+1),mem*=B,mem+=(s2[j]-'a'+1),mem*=B,mem+=27;
        for(int j(fir-1);~j;--j) mem*=B,mem+=(s1[j]-'a'+1);
        if(las!=-1) for(int j(las+1);j<s1.length();++j) u+=s1[j];
        mp[mem].insert(u);
    }
    for(int i(1),fir,las;i<=q;++i){
        cin >> s1 >> s2,fir=s1.length(),las=-1,mem=ans=0,u.clear();
        for(int j(0);j<s1.length();++j) if(s1[j]!=s2[j]) fir=min(fir,j),las=max(las,j);
        for(int j(fir);j<=las;++j) mem*=B,mem+=(s1[j]-'a'+1),mem*=B,mem+=(s2[j]-'a'+1),mem*=B,mem+=27;
        if(las!=-1) for(int j(las+1);j<s1.length();++j) u+=s1[j];
        ans+=mp[mem].ans(u);
        for(int j(fir-1);~j;--j) mem*=B,mem+=(s1[j]-'a'+1),ans+=mp[mem].ans(u);
        cout << ans << '\n';
    }
    return 0;
}