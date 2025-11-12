#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
typedef long long ll;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<48||ch>57){if(ch=='-')f=-1;ch=getchar();}
    while(48<=ch&&ch<=57){x=(x*10)+(ch^48);ch=getchar();}
    return x*f;
}

const int N=5e6+1000;

char str1[N],str2[N];

struct node{
    int pos;
    std::pair<int,int> p;
};

bool operator<(node a,node b)
{
    if(a.pos==b.pos)
        return a.p<b.p;

    return a.pos<b.pos;
}

struct ACAM{

    int ch[N][26],cnt=0;

    int next[N];

    std::vector<std::pair<int,int> > vec[N];

    void insert(char *str,int id)
    {
        int now=0,len=0;

        for(int i=1;str[i];i++)
        {
            if(!ch[now][str[i]-'a'])
                ch[now][str[i]-'a']=++cnt;

            now=ch[now][str[i]-'a'];

            ++len;
        }

        vec[now].push_back({len,id});
    }

    void build()
    {
        std::queue<int> q;

        for(int i=0;i<26;i++)
            if(ch[0][i])
                q.push(ch[0][i]);

        while(q.size())
        {
            int x=q.front();q.pop();

            for(int i=0;i<26;i++)
            {
                int y=ch[x][i];

                if(!y)
                    ch[x][i]=ch[next[x]][i];
                else next[y]=ch[next[x]][i],q.push(y);
            }
        }
    }

    std::vector<int> v[N];

    int tag[N];

    void clear()
    {
        memset(tag,0,sizeof(int)*(cnt+5));
    }

    void search(char *str,std::set<node> &temp,const int l,const int r)
    {
        int now=0;

        for(int i=1;str[i];i++)
        {
            now=ch[now][str[i]-'a'];

            for(int j=now;j;j=next[j])
            {
                for(auto p:vec[j])
                {
                    if(i>=r&&i-p.first+1<=l)
                        temp.insert({i,p});
                }
            }
        }
    }

}AC,AC2;

void solve()
{
    scanf("%s%s",str1+1,str2+1);

    int n=strlen(str1+1),m=strlen(str2+1),l=n+1,r=0;

    if(n!=m)
    {
        puts("0");
        return;
    }

    for(int i=1;str1[i];i++)
    {
        if(str1[i]!=str2[i])
        {
            l=i;
            break;
        }
    }

    for(int i=n;i>=1;i--)
    {
        if(str1[i]!=str2[i])
        {
            r=i;
            break;
        }
    }

    std::set<node> v1,v2;

    AC.clear();
    AC.search(str1,v1,l,r);

    AC2.clear();
    AC2.search(str2,v2,l,r);

    if(v1.size()>v2.size())
        std::swap(v2,v1);

    ll ans=0;

    for(node it:v1)
    {
        if(v2.find(it)!=v2.end())
            ans++;
    }

    printf("%lld\n",ans);
}

int n,q;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    n=read(),q=read();

    for(int i=1;i<=n;i++)
    {
        scanf("%s%s",str1+1,str2+1);
        AC.insert(str1,i),AC2.insert(str2,i);
    }

    AC.build(),AC2.build();

    while(q--)
        solve();

    return 0;
}

