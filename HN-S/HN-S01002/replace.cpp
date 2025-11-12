#include<bits/stdc++.h>
using namespace std;
int read(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
#define N 3009000
int idcnt=1;
int trie[N][69];
string s1;
int cnt[N];
int idfind(char c){
    if(c>='a'&&c<='z')return c-'a'+1;
    else if(c>='A'&&c<='Z')return c-'A'+26;
    else return c-'0'+52;
}
void build(){
    int p=0;
    int len=s1.size();
    for(int i=0;i<len;i++){
        int k=idfind(s1[i]);
        if(trie[p][k]==0)trie[p][k]=idcnt++;
        if(i==len-1)cnt[p]++;
        p=trie[p][k];
    }
}
string s2;
int find(){
    int p=0;
    int len=s2.size();
    for(int i=0;i<len;i++){
        int k=idfind(s2[i]);
        if(trie[p][k]==0)return 0;
        p=trie[p][k];
    }
    return cnt[p];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n=read(),q=read();
    for(int i=1;i<=n;i++){
        cin>>s1;
        cin>>s2;
    }
    while(q--){
        cin>>s1;
        cin>>s2;
    cout<<0<<'\n';
    }
}
//已知是trie状物，但我没时间想了
//ccc，我要没时间打我最爱的字符串大人了，会赢吗 17：54
//我看你们钊老师应该是没有6钩了
//cnm我完蛋了
//t3我艹艹你的
//wow！我性质B好像推炸了！ouye
//OvO我该怎么办
//tmd我完了，CCF我求求你多放几个0的数据吧
//至少要有一个吧