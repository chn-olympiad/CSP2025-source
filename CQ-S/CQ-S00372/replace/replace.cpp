#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using ull=unsigned long long;
constexpr int maxn=2e5+5,maxc=1.1e7;
int n,q,cnt,qz[maxn],hz[maxn],cnts=1,rt[maxn];
std::string s1[maxn],s2[maxn];
std::vector<int>e[maxn];
struct trie{int son[26];long long cnt;}tr[maxc];
int main(){
    std::freopen("replace.in","r",stdin);
    std::freopen("replace.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>n>>q;
    for(int i=1;i<=n;++i){
        std::cin>>s1[i]>>s2[i];
        if(s1[i]==s2[i]){--i;--n;continue;}
        for(int j=0;;++j) if(s1[i][j]!=s2[i][j]){qz[i]=j;break;}
        for(int j=(int)s1[i].size()-1;;--j) if(s1[i][j]!=s2[i][j]){hz[i]=j;break;}
        std::string str=s1[i].substr(qz[i],hz[i]-qz[i]+1),str2=s2[i].substr(qz[i],hz[i]-qz[i]+1);
        int p=1;
        for(char c:str){
            if(!tr[p].son[c-'a']) tr[p].son[c-'a']=++cnts;
            p=tr[p].son[c-'a'];
        }
        if(!tr[p].cnt) tr[p].cnt=++cnts;
        p=tr[p].cnt;
        for(char c:str2){
            if(!tr[p].son[c-'a']) tr[p].son[c-'a']=++cnts;
            p=tr[p].son[c-'a'];
        }
        if(!tr[p].cnt) tr[p].cnt=++cnt;
        e[tr[p].cnt].push_back(i);
    }
    for(int i=1;i<=cnt;++i){
        rt[i]=++cnts;
        std::sort(e[i].begin(),e[i].end(),[](int x,int y){return qz[x]<qz[y];});
        for(int j:e[i]){
            int p=rt[i];
            for(int k=qz[j]-1;k>=0;--k){
                int c=s1[j][k]-'a';
                if(!tr[p].son[c]) tr[++cnts].cnt=tr[p].cnt,tr[p].son[c]=cnts;
                p=tr[p].son[c];
            }
            tr[++cnts]=tr[tr[p].cnt];
            p=tr[p].cnt=cnts;
            for(int k=hz[j]+1;k<(int)s1[j].size();++k){
                int c=s1[j][k]-'a';
                tr[++cnts]=tr[tr[p].son[c]];
                tr[p].son[c]=cnts;
                p=cnts;
            }
            ++tr[p].cnt;
        }
    }for(int i=1;i<=q;++i){
        long long res=0;
        std::string t1,t2;
        std::cin>>t1>>t2;
        if(t1.size()!=t2.size()){std::cout<<"0\n";continue;}
        int qz=0,hz=0;
        for(int j=0;;++j) if(t1[j]!=t2[j]){qz=j;break;}
        for(int j=(int)t1.size()-1;;--j) if(t1[j]!=t2[j]){hz=j;break;}
        std::string str=t1.substr(qz,hz-qz+1),str2=t2.substr(qz,hz-qz+1);
        int p=1;
        bool flag=true;
        for(char c:str){
            if(!tr[p].son[c-'a']){flag=false;break;}
            p=tr[p].son[c-'a'];
        }
        if(!flag||!tr[p].cnt){std::cout<<"0\n";continue;}
        p=tr[p].cnt;
        for(char c:str2){
            if(!tr[p].son[c-'a']){flag=false;break;}
            p=tr[p].son[c-'a'];
        }
        if(!flag||!tr[p].cnt){std::cout<<"0\n";continue;}
        p=rt[tr[p].cnt];
        for(int k=qz-1;k>=0;--k){
            int c=t1[k]-'a';
            if(tr[p].son[c]) p=tr[p].son[c];
            else break;
        }
        p=tr[p].cnt;
        res+=tr[p].cnt;
        for(int k=hz+1;k<(int)t1.size();++k){
            int c=t1[k]-'a';
            if(!tr[p].son[c]) break;
            p=tr[p].son[c];
            res+=tr[p].cnt;
        }
        std::cout<<res<<'\n';
    }
    return 0;
}