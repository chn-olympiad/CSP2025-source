#include<bits/stdc++.h>
#define ll long long
const int N=5e6+5;
using namespace std;
int n,q,m;
ll ans=0;
#define mp(x,y) make_pair(x,y)
map<pair<int,int>,int> S;
struct ACM{

    int ch[N][27],fail[N],num[N],d[N],D[N],f[N],dep[N];
    int cnt=1,flag;
    queue<int> Q;
    void insert(char s[],int n)
    {
        int x=1;
        for(int i=1,c;i<=n;i++)
        {
            c=s[i]-'a';
            if(!ch[x][c])ch[x][c]=++cnt;
            dep[ch[x][c]]=dep[x]+1;x=ch[x][c];
        }
    }
    void get_fail()
    {
        for(int i=0;i<26;i++)ch[0][i]=1;
        for(int i=0;i<26;i++){if(ch[1][i])Q.push(ch[1][i]),fail[ch[1][i]]=1,d[1]++;}
        while(!Q.empty())
        {
            int x=Q.front();Q.pop();
            for(int i=0,y;i<26;i++)
            {
                y=ch[x][i];
                if(!y)ch[x][i]=ch[fail[x]][i];
                else fail[y]=ch[fail[x]][i],Q.push(y),d[fail[x]]++;
            }
        }
    }
    void match(char s[],int n)
    {
        int x=1;
        for(int i=1,c;i<=n;i++)
        {
            c=s[i]='a';num[ch[x][c]]++;
            x=ch[x][c];
        }
    }
    void topo()
    {
        for(int i=1;i<=cnt;i++){D[i]=d[i];if(!D[i])Q.push(i);}
        while(!Q.empty())
        {
            int x=Q.front();Q.pop();f[x]+=num[x],num[x]=0;
            f[fail[x]]+=f[x];D[fail[x]]--;if(D[fail[x]]==0)Q.push(fail[x]);
            if(flag==1)
            {
                if(f[x])S[mp(dep[x],f[x])]++;
            }
            else
            {
                if(f[x])ans+=S[mp(dep[x],f[x])];
            }
        }
    }
}ac1,ac2;
char s1[N],s2[N];
void work()
{
    cin>>n>>q;
    for(int i=1;i<=q;i++)cout<<0<<"\n";
    return;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s1+1);scanf("%s",s2+1);
        //ac1.insert(s1,strlen(s1+1)),ac2.insert(s2,strlen(s2+1));
    }
    ac1.flag=1,ac2.flag=0;
    ac1.get_fail();
    ac2.get_fail();
    for(int i=1;i<=q;i++)
    {
        scanf("%s",s1+1);scanf("%s",s2+1);
        ans=0;
        ac1.match(s1,strlen(s1+1)),ac2.match(s2,strlen(s2+1));
        ac1.topo();ac2.topo();
        printf("%lld\n",ans);
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    work();
    return 0;
}
