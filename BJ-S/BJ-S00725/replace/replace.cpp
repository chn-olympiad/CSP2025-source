#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5000000+10,MAXN=5000000,Q=2e5,T=26,_1=37,_2=31,M1=998244353,M2=1e9+7;
const char char_tag='z'+1;
/*int pw1[N],pw2[N];
struct HASH{
    int h1,h2,len;
    inline bool operator<(const HASH&rhs)const{return h1!=rhs.h1?h1<rhs.h1:h2<rhs.h2;}
    inline bool operator>(const HASH&rhs)const{return h1!=rhs.h1?h1>rhs.h1:h2>rhs.h2;}
    inline HASH operator-(const HASH&rhs)const{
        if(len<rhs.len)return;
        int newlen=len-rhs.len;
        HASH newhsh;
        newhsh.h1=(h1-rhs.h1*pw1[newlen]%M1+M1)%M1;
        newhsh.h2=(h2-rhs.h2*pw2[newlen]%M2+M2)%M2;
        return newhsh;
    }
    inline HASH operator+(const char &w){
        HASH newhash;newhash.len=len+1;
        newhash.h1=(h1*_1+w-'a'+1)%M1,newhash.h2=(h2*_2+w-'a'+1)%M2;
        return newhash;
    }
};
struct CHANGE{
    HASH s,e;
    inline bool operator<(const CHANGE&rhs)const{return s!=rhs.s?s<rhs.s:e<rhs.e;}
    inline bool operator<(const CHANGE&rhs)const{return s!=rhs.s?s>rhs.s:e>rhs.e;}
};
map<CHANGE,int>mp;*/
struct NODE{
    string s;int id;
};
vector<NODE>query[N+Q*2];vector<string>modify[N+Q*2];
int n,m;
int trie_modify[N+Q*2][28],trie[N][28],val[N],ans[N],posm,pos,rootm,root;

inline string solve(string s1,string s2){
    string s3;
    int p=s1.length()-1;while(p>=0&&s1[p]==s2[p])p--;
    int q=0;while(s1[q]==s2[q])s3+=s1[q],q++;s3+=char_tag;
    //cout<<"\t"<<s3<<','<<q<<','<<p<<endl;
    for(int i=q;i<=p;i++)s3+=s1[i];s3+=char_tag;
    //cout<<"\t"<<s3<<endl;
    for(int i=q;i<=p;i++)s3+=s2[i];
    reverse(s3.begin(),s3.end());
    //cout<<"SOLVE:   "<<s1<<','<<s2<<"-->"<<s3<<endl;
    return s3;
}

/// start build part of trie
inline void insert_modify_trie(string s,string mdf){
    int p=rootm;
    for(int i=0,w;i<s.length();i++){
        w=s[i]-'a';
        if(!trie_modify[p][w])trie_modify[p][w]=++posm;
        p=trie_modify[p][w];
    }
    //cout<<"!!!"<<p<<"+M"<<','<<mdf<<endl;
    modify[p].push_back(mdf);
}
inline void insert_query_trie(string s,NODE qry){
    int p=rootm;
    for(int i=0,w;i<s.length();i++){
        w=s[i]-'a';
        if(!trie_modify[p][w])break;
        p=trie_modify[p][w];
    }
    query[p].push_back(qry);
}

inline void insert(){
    string s1,s2,s3,s5;
    cin>>s1>>s2;if(s1==s2)return;s3=s5="";
    int p=s1.length()-1;while(p>=0&&s1[p]==s2[p])p--;
    s3=solve(s1,s2);
    for(int i=p+1;i<s1.length();i++)s5+=s1[i];
    insert_modify_trie(s3,s5);
}
inline void insert_query(string s1,string s2,int id){
    string s3,s5;s3=s5="";
    int p=s1.length()-1;while(p>=0&&s1[p]==s2[p])p--;
    s3=solve(s1,s2);
    for(int i=p+1;i<s1.length();i++)s5+=s1[i];
    //cout<<"!!!INSERT QUERY  "<<s3<<','<<s5<<','<<id<<endl;
    insert_query_trie(s3,{s5,id});
}
int tmp=0;
void insert_string(string s){
    int p=root;
    for(int i=0,w;i<s.length();i++){
        w=s[i]-'a';
        if(trie[p][w]==0)trie[p][w]=++pos;
        p=trie[p][w];
        //cout<<"!!!insert string :  "<<val[p]<<endl;
    }
    //cout<<"INSERT "<<s<<endl;
    val[p]++;
}
void delete_string(string s){
    int p=root;
    for(int i=0,w;i<s.length();i++){
        w=s[i]-'a';
        if(trie[p][w]==0)trie[p][w]=++pos;
        p=trie[p][w];
    }
    //cout<<"DELETE "<<s<<endl;
    val[p]--;
}
int query_string(string s){
    int p=root,res=val[root];
    //cout<<"\t\t"<<s<<"->"<<val[root]<<endl;
    for(int i=0,w;i<s.length();i++){
        w=s[i]-'a';
        if(trie[p][w]==0)break;
        res+=val[p=trie[p][w]];
        //cout<<"\t"<<val[p]<<endl;
    }
    return res;
}
/// end build part of trie

/// start solve problem
void calc(int u){
    //cout<<u<<": "<<modify[u].size()<<endl;
    for(auto i:modify[u]){
        insert_string(i);
    }
    for(auto i:query[u]){
        //cout<<"\tQUERY: "<<i.id<<";  "<<i.s<<endl;
        ans[i.id]=query_string(i.s);
    }
    for(int i=0;i<=26;i++){
        if(trie_modify[u][i])calc(trie_modify[u][i]);
    }
    for(auto i:modify[u])delete_string(i);
}
/// end solve problem
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    //pw1[0]=pw2[0]=1;for(int i=1;i<=MAXN;i++)pw1[i]=pw1[i-1]*_1%M1,pw2[i]=pw2[i-1]*_2%M2;
    cin>>n>>m;string s1,s2;
    for(int i=1;i<=n;i++)insert();
    for(int i=1;i<=m;i++){
        cin>>s1>>s2;
        if(s1.length()!=s2.length())continue;
        insert_query(s1,s2,i);
    }
    calc(rootm);
    //cout<<tmp<<endl;
    for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
    return 0;
}
