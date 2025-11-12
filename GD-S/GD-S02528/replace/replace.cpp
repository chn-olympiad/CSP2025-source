#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define ull unsigned long long
const int N=1e6+10,M=5e6+10,P=131;
int n,m,fra[N],eda[N],frb[N],edb[N],lena[N],lenb[N];
vector<char>a[N],b[N];
vector<ull>s1[N],s2[N];
char ch[M],ch1[M];
ull pw[M],vala[N][2],valb[N][2];
void init()
{
    pw[0]=1;
    for(int i=1;i<M;i++) pw[i]=pw[i-1]*P;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ch+1);
        int len=strlen(ch+1);
        scanf("%s",ch1+1);
        for(int j=1;j<=len;j++)
        {
            if(ch[j]!=ch1[j]){fra[i]=j;break;}
        }
        for(int j=len;j>=1;j--)
        {
            if(ch[j]!=ch1[j]){eda[i]=j;break;}
        }
        for(int j=fra[i];j<=eda[i];j++) vala[i][0]=vala[i][0]+pw[j-fra[i]]*(ch[j]-'a'+1);
        for(int j=fra[i];j<=eda[i];j++) vala[i][1]=vala[i][1]+pw[j-fra[i]]*(ch1[j]-'a'+1);
        a[i].resize(len+1),s1[i].resize(len+1);
        for(int j=1;j<=len;j++) a[i][j]=ch[j],s1[i][j]=s1[i][j-1]+pw[j]*(a[i][j]-'a'+1);
        lena[i]=len;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%s",ch+1);
        int len=strlen(ch+1);
        scanf("%s",ch1+1);
        for(int j=1;j<=len;j++)
        {
            if(ch[j]!=ch1[j]){frb[i]=j;break;}
        }
        for(int j=len;j>=1;j--)
        {
            if(ch[j]!=ch1[j]){edb[i]=j;break;}
        }
        for(int j=frb[i];j<=edb[i];j++) valb[i][0]=valb[i][0]+pw[j-frb[i]]*(ch[j]-'a'+1);
        for(int j=frb[i];j<=edb[i];j++) valb[i][1]=valb[i][1]+pw[j-frb[i]]*(ch1[j]-'a'+1);
        b[i].resize(len+1),s2[i].resize(len+1);
        for(int j=1;j<=len;j++) b[i][j]=ch[j],s2[i][j]=s2[i][j-1]+pw[j]*(b[i][j]-'a'+1);
        lenb[i]=len;
    }
    for(int i=1;i<=m;i++)
    {
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            if(valb[i][0]==vala[j][0]&&valb[i][1]==vala[j][1])
            {
                int qi=frb[i]-(fra[j]-1),zh=edb[i]+(lena[j]-eda[j]);
                if(qi>0&&qi<=lenb[i]&&zh>0&&zh<=lenb[i]&&qi<=zh&&s1[j][lena[j]]*pw[qi-1]==(s2[i][zh]-s2[i][qi-1])) ans++;
            }
        }
        printf("%d\n",ans);
    }
}
