#include <bits./stdc++.h>
using namespace std;

const int N=6e5+5;
int n,q,h[N],path[N][24],l[N];
char s[2][N];

struct ACAM{
    int tot,trie[N][26],fail[N];
    void insert(int id){
        int u=0,len=strlen(s[id]+1);
        for(int i=1;i<=len;i++){
            if(!trie[u][s[id][i]-'a'])trie[u][s[id][i]-'a']=++tot;
            u=trie[u][s[id][i]-'a'];
        }
    }
}; 

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //this code is just a joke
    //I forgot how to build ACAM
    return 0;
}