#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int N=200005,V=5e6+5,base1=233,base2=97;
int n,q,tot,cnt;
string s1,s2;

struct trie{
    int ch[26];
}tr[V];
multiset<ull>st[N];

int solve(int x,char ch){
    int y=ch-'a';
    if(!tr[x].ch[y])tr[x].ch[y]=++tot;
    return tr[x].ch[y];
}

map<ull,int>mp[V];
int f(int x,ull hsh){
    if(mp[x][hsh]==0)mp[x][hsh]=++cnt;
    return mp[x][hsh];
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int _=1;_<=n;_++){
        cin>>s1>>s2;
        if(s1==s2){ // impossible
            n--;_--;
            continue;
        }
        int m=s1.size(),stt=-1,ed=-1;
        for(int i=0;i<m;i++){
            if(s1[i]==s2[i])continue;
            if(stt==-1)stt=i;
            ed=i;
        }
        ull hsh1=0,hsh2=0;
        for(int i=stt;i<=ed;i++){
            hsh1=hsh1*base1+s1[i];
            hsh2=hsh2*base2+s2[i];
        }
        ull hsh=hsh1*114+hsh2*23*(hsh1-1); // wtf???
        int cur=0;
        for(int i=stt-1;i>=0;i--)
            cur=solve(cur,s1[i]);
        hsh1=0,hsh2=0;
        ull hx=0;
        for(int i=ed+1;i<m;i++){
            hsh1=hsh1*base1+s1[i];
            hsh2=hsh2*base2+s2[i];
        }
        hx=hsh1*114+(hsh2-1)*23*(hsh1-1); // wtf???
        st[ f(cur,hsh) ].insert(hx);
    }
    for(int _=1;_<=q;_++){
        cin>>s1>>s2;
        int m=s1.size(),stt=-1,ed=-1;
        for(int i=0;i<m;i++){
            if(s1[i]==s2[i])continue;
            if(stt==-1)stt=i;
            ed=i;
        }
        ull hsh1=0,hsh2=0;
        for(int i=stt;i<=ed;i++){
            hsh1=hsh1*base1+s1[i];
            hsh2=hsh2*base2+s2[i];
        }
        ull hsh=hsh1*114+hsh2*23*(hsh1-1); // wtf???
        ull hx=0;
        set<ull>S;
        hsh1=hsh2=0;
        hx=hsh1*114+(hsh2-1)*23*(hsh1-1); // wtf???
        S.insert(hx);
        for(int i=ed+1;i<m;i++){
            hsh1=hsh1*base1+s1[i];
            hsh2=hsh2*base2+s2[i];
            hx=hsh1*114+(hsh2-1)*23*(hsh1-1); // wtf???
            S.insert(hx);
        }
        int cur=0,ans=0;
        if(mp[cur][hsh])
        for(auto v:st[ f(cur,hsh) ])
            if(S.find(v)!=S.end())ans++;
        for(int i=stt-1;i>=0;i--){
            cur=solve(cur,s1[i]);
            if(mp[cur][hsh])
            for(auto v:st[ f(cur,hsh) ])
                if(S.find(v)!=S.end())ans++;
        }
        cout<<ans<<'\n';
    }
}
