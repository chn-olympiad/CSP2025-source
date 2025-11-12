#include<cstdio>
#include<cstring>
using namespace std;

const int nn=1000006;
const long long mod1=456456397;
const long long mod2=456456359;

long long w29[nn],w31[nn];

int n;
char a1[nn],a2[nn];

long long *h1[nn],*h2[nn];
int Len[nn],L[nn],R[nn];

long long g1[nn],g2[nn];

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    w29[0]=1,w31[0]=1;
    for(int i=1;i<nn;i++) w29[i]=w29[i-1]*29%mod1,w31[i]=w31[i-1]*31%mod2;

    int q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a1+1);
        scanf("%s",a2+1);
        int len=strlen(a1+1);
        h1[i]=new long long[len+1];
        h2[i]=new long long[len+1];
        h1[i][0]=h2[i][0]=0;

        L[i]=1,R[i]=len,Len[i]=len;
        while(a1[L[i]]==a2[L[i]]&&L[i]<=n) L[i]++;
        while(a1[R[i]]==a2[R[i]]&&R[i]>=1) R[i]--;
        if(R[i]==0) Len[i]=-1;

        for(int j=1;j<=len;j++)
        {
            h1[i][j]=(h1[i][j-1]*29+a1[j]-'a'+1)%mod1;
            h2[i][j]=(h2[i][j-1]*31+a2[j]-'a'+1)%mod2;
        }

        //printf("i=%d L=%d,R=%d\n",i,L[i],R[i]);//
        //printf("h1=%lld,h2=%lld\n",h1[i][Len[i]],h2[i][Len[i]]);
    }

    while(q--)
    {
        int ans=0;

        scanf("%s",a1+1);
        scanf("%s",a2+1);
        int len=strlen(a1+1);

        for(int j=1;j<=len;j++)
        {
            g1[j]=(g1[j-1]*29+a1[j]-'a'+1)%mod1;
            g2[j]=(g2[j-1]*31+a2[j]-'a'+1)%mod2;
        }

        int left=1,right=len;
        while(a1[left]==a2[left]) left++;
        while(a1[right]==a2[right]) right--;
        //printf("left=%d,right=%d\n",left,right);//

        for(int i=1;i<=n;i++)
        {
            if(R[i]-L[i]!=right-left) continue;
            long long jie1=(g1[right+Len[i]-R[i]]-g1[left-L[i]]*w29[Len[i]])%mod1;
            if(jie1<0) jie1+=mod1;
            long long jie2=(g2[right+Len[i]-R[i]]-g2[left-L[i]]*w31[Len[i]])%mod2;
            if(jie2<0) jie2+=mod2;
            //printf("jie1=%lld,jie2=%lld\n",jie1,jie2);//
            if(h1[i][Len[i]]==jie1&&h2[i][Len[i]]==jie2) ans++;
        }

        printf("%d\n",ans);
    }

    return 0;
}

/*#include<cstdio>
#include<cstring>
using namespace std;

const int nn=200005;
const int n2=nn<<1;

char a1[nn],a2[nn];

void Add(int);
void bfs1();
long long dfs1(int,int,int);
int ch[n2][26],nxt[n2],dep[n2],cnt[n2],xn;
int team[n2],tail;

long long solve();

int search(int,int,int);
int sx[n2];

int main()
{
    freopen("replace1.in","r",stdin);

    for(int i=0;i<n2;i++) sx[i]=-1;

    int n,q;
    scanf("%d%d",&n,&q);

    xn=1;

    while(n--)
    {
        scanf("%s",a1+1);
        scanf("%s",a2+1);
        Add(strlen(a1+1));
    }

    nxt[0]=nxt[1]=1;
    team[tail=1]=1;
    bfs1();

    while(q--)
    {
        scanf("%s",a1+1);
        scanf("%s",a2+1);
        printf("%lld\n",solve());
    }

    return 0;
}
void Add(int len)
{
    int u=1;
    for(int i=1;i<=len;i++)
    {
        if(!ch[u][a1[i]-'a']) dep[ch[u][a1[i]-'a']=++xn]=dep[u]+1;
        u=ch[u][a1[i]-'a'];
        if(!ch[u][a2[i]-'a']) dep[ch[u][a2[i]-'a']=++xn]=dep[u];
        u=ch[u][a2[i]-'a'];
    }
    cnt[u]++;
    return;
}
void bfs1()
{
    for(int head=1,u;head<=tail;head++)
    {
        u=team[tail];
        for(int i=0;i<26;i++)
        {
            if(ch[u][i])
            {
                nxt[ch[u][i]]=ch[nxt[u]][i];
                team[++tail]=u;
            }
            else ch[u][i]=ch[nxt[u]][i];
        }
    }

    for(int i=1;i<=xn;i++)
    {
        printf("nxt[%d]=%d ch[%d][]=",i,nxt[i],i);//
        for(int j=0;j<26;j++) printf("%d ",ch[i][j]);puts("");//
    }

    for(int i=1;i<=xn;i++)
    {
        if(!sx[nxt[i]]&&!cnt[i]) sx[i]=0;
    }

    return;
}
long long solve()
{
    int len=strlen(a1+1);
    int left=1,right=len;
    while(a1[left]==a2[left]) left++;
    while(a1[right]==a2[right]) right--;
    return dfs1(len,left,right);
}
long long dfs1(int len,int left,int right)
{
    tail=0;

    long long res=0;
    int u=1;
    for(int i=1;i<=len;i++)
    {
        u=ch[u][a1[i]-'a'];
        u=ch[u][a2[i]-'a'];
        if(!u) u=1;

        if(i>=right&&dep[u]>=right-left+1)
        {
            res+=search(u,left,right);
            printf("i=%d res=%lld\n",i,res);//
        }
    }

    while(tail)
    {
        sx[team[tail]]=-1;
        tail--;
    }

    return res;
}
int search(int u,int left,int right)
{
    printf("search-OK0 u=%d,left=%d,right=%d\n",u,left,right);//
    if(sx[u]!=-1) return sx[u];
    if(dep[u]<right-left+1) return 0;
    team[++tail]=u;
    return sx[u]=cnt[u]+search(nxt[u],left,right);
}*/
