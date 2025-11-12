#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void rd(int &p){
    p=0;char z=getchar();int f(0);
    while(z>'9'||z<'0'){if(z=='-')f^=1;z=getchar();}
    while(z>='0'&&z<='9')p=(p<<1)+(p<<3)+z-'0',z=getchar();
    if(f)p=-p;
}
void rdl(ll &p){
    p=0;char z=getchar();int f(0);
    while(z>'9'||z<'0'){if(z=='-')f^=1;z=getchar();}
    while(z>='0'&&z<='9')p=(p<<1)+(p<<3)+z-'0',z=getchar();
    if(f)p=-p;
}
const int N=2e5+5;
int n,q,ct1(0),ct2(0),u;
string s1[N],s2[N],S1,S2;
struct trie{
    char c[26];int fl;
    vector<int>v;
    void cl(){
        memset(c,0,sizeof(c));fl=0;
    }
}t1[5000005],t2[5000005];
void add1(int x){
    if(!t1[u].c[x]){
        t1[u].c[x]=++ct1;t1[ct1].cl();
    }u=t1[u].c[x];
    //printf("%d\n",u);
}
void add2(int x){
    if(!t2[u].c[x]){
        t2[u].c[x]=++ct2;t2[ct2].cl();
    }u=t2[u].c[x];
}
queue<int>Q;
bool b[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    rd(n);rd(q);
    for(int i(1);i<=n;++i)cin>>s1[i]>>s2[i];
    for(int i(1);i<=n;++i){u=0;
        for(int j(0);j<s1[i].size();++j)add1(s1[i][j]-'a');
        t1[u].v.push_back(i);
        u=0;
        for(int j(0);j<s2[i].size();++j)add2(s2[i][j]-'a');
        t2[u].v.push_back(i);
        //cout<<ct1<<' '<<ct2<<endl;
    }
    for(int i(0);i<26;++i){
        if(t1[0].c[i]){
            Q.push(t1[0].c[i]);
        }
    }
    while(Q.size()){
        u=Q.front();Q.pop();
        for(int i(0);i<26;++i){
            if(t1[u].c[i]){
                t1[t1[u].c[i]].fl=t1[t1[u].fl].c[i];
                Q.push(t1[u].c[i]);
            }
            else{
                t1[u].c[i]=t1[t1[u].fl].c[i];
            }
        }
        for(int i(0);i<t1[t1[u].fl].v.size();++i)t1[u].v.push_back(t1[t1[u].fl].v[i]);
    }
    for(int i(0);i<26;++i){
        if(t2[0].c[i]){
            Q.push(t2[0].c[i]);
        }
    }
    while(Q.size()){
        u=Q.front();Q.pop();
        for(int i(0);i<26;++i){
            if(t2[u].c[i]){
                t2[t2[u].c[i]].fl=t2[t2[u].fl].c[i];
                Q.push(t2[u].c[i]);
            }
            else{
                t2[u].c[i]=t2[t2[u].fl].c[i];
            }
        }
        for(int i(0);i<t2[t2[u].fl].v.size();++i)t2[u].v.push_back(t2[t2[u].fl].v[i]);
    }
    // for(int i(0);i<=ct1;++i){
    //     printf("%d ",t1[i].fl);
    // }puts("");
    while(q--){
        cin>>S1>>S2;
        if(S1.size()!=S2.size())printf("0\n");
        else{
            int u1(0),u2(0),ans(0),l(0),r(S1.size()-1);
            while(l<S1.size()&&S1[l]==S2[l])++l;
            while(r>=0&&S1[r]==S2[r])--r;
            //printf("%d %d\n",l,r);
            for(int i(0);i<S1.size();++i){
                u1=t1[u1].c[S1[i]-'a'];u2=t2[u2].c[S2[i]-'a'];
                if(i<r)continue;
                for(int j(0);j<t1[u1].v.size();++j)b[t1[u1].v[j]]=true;
                // printf("i:%d\n",i);
                // for(int j(0);j<t1[u1].v.size();++j)printf("%d ",t1[u1].v[j]);puts("");
                // for(int j(0);j<t2[u2].v.size();++j)printf("%d ",t2[u2].v[j]);puts("");
                for(int j(0);j<t2[u2].v.size();++j){
                    //printf("%d %d %d\n",b[t2[u2].v[j]],i-s1[t2[u2].v[j]].size(),l);
                    if(b[t2[u2].v[j]]&&(int)(i-s1[t2[u2].v[j]].size())<l){
                        ++ans;//cout<<"Q"<<endl;
                    }
                }
                for(int j(0);j<t1[u1].v.size();++j)b[t1[u1].v[j]]=false;
            }printf("%d\n",ans);
        }
    }
    return 0;
}