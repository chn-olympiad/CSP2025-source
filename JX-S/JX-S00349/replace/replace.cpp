#include<bits/stdc++.h>
#define DEBUG
#ifdef DEBUG
#define perr(...) fprintf(stderr,__VA_ARGS__)
#else
#define perr(...) void(0)
#endif
using namespace std;
const int ms=5e6+5;
int n,q;
int get(char c)
{
    if(c&32)return c-'a';
    return c-'A'+26;
}
char a[ms],b[ms],c[ms];
int clen;
namespace Trie
{
    int a[ms][52];
    struct node
    {
        int c,id;
    };
    vector<node> v[ms];
    int fa[ms],fail[ms],s[ms];
    int ncnt=1;
    void insert(char *x,int len)
    {
        int t=1;
        for(int i=1;i<=len;i++)
        {
            int k=get(x[i]);
            if(!a[t][k])
            {
                a[t][k]=++ncnt;
                v[t].push_back({k,ncnt});
                fa[ncnt]=t;
            }
            t=a[t][k];
        }
        ++s[t];
    }
    queue<int> q;
    void build()
    {
        fail[1]=1;
        for(auto i:v[1])
        {
            fail[i.id]=1;
            q.push(i.id);
        }
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(auto i:v[t])
            {
                int tmp=fail[t];
                while(!a[tmp][i.c] && tmp!=1)tmp=fail[tmp];
                if(a[tmp][i.c])tmp=a[tmp][i.c];
                fail[i.id]=tmp;
                s[i.id]+=s[tmp];
                q.push(i.id);
            }
        }
    }
    int qry(char *x,int len)
    {
        int res=0;
        int t=1;
        for(int i=1;i<=len;i++)
        {
            int k=get(x[i]);
            // if(k<0)perr("%c %d\n",x[i],strlen(x));
            // assert(k>=0);
            while(t!=1 && !a[t][k])t=fail[t];
            if(a[t][k])t=a[t][k];
            res+=s[t];
        }
        return res;
    }
}
bool proc()//a && b -> c
{
    clen=0;
    int fst,lst;
    int tmp=strlen(a+1);
    if(strlen(b+1)!=tmp)return 0;
    fst=lst=0;
    for(int i=1;i<=tmp;i++)
    {
        if(a[i]!=b[i])
        {
            if(!fst)fst=i;
            lst=i;
        }
    }
    if(fst==0)return 0;
    for(int i=1;i<fst;i++)c[++clen]=a[i];
    c[++clen]=(a[fst]^32);
    for(int i=fst+1;i<=lst;i++)c[++clen]=a[i];
    for(int i=fst;i<lst;i++)c[++clen]=b[i];
    c[++clen]=(b[lst]^32);
    for(int i=lst+1;i<=tmp;i++)c[++clen]=b[i];
    c[clen+1]=0;
    return 1;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&n,&q);
    // int tot=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a+1);
        scanf("%s",b+1);
        // tot+=strlen(a+1)+strlen(b+1);
        if(proc())Trie::insert(c,clen);
        // perr("%s %d\n",c+1,clen);
    }
    // printf("")
    Trie::build();
    for(int i=1;i<=q;i++)
    {
        scanf("%s",a+1);
        scanf("%s",b+1);
        if(!proc())printf("0\n");
        else printf("%d\n",Trie::qry(c,clen));
    }
}