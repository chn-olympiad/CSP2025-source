#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=10011;
const int M=2010;

inline int read()
{
	int f=1,x=0; char ch=getchar();
	while(!isdigit(ch)) {  if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch))  {  x=x*10+ch-'0';    ch=getchar(); }
	return f*x;
}

int n,m;
char s1[N][M],s2[N][M],s[M];
char t1[M],t2[M],tmp[M];

int nxt[M];

inline void calc()
{
    int pos=0;
    for(int i=2;s[i];i++)
    {
        while(pos>0 && s[pos+1]!=s[i])
          pos=nxt[pos];
        if(s[pos+1]==s[i]) pos++;
        nxt[i]=pos;
    }
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
      scanf("%s %s\n",s1[i]+1,s2[i]+1);
    while(m--)
    {
        scanf("%s %s\n",t1+1,t2+1);
        int ans=0;
        for(int i=1;t1[i];i++) tmp[i]=t1[i];
        for(int i=1;i<=n;i++)
        {
            memset(nxt,0,sizeof(nxt));
            for(int j=1;s1[i][j];j++) s[j]=s1[i][j];
            calc();
            int pos=0,len=strlen(s+1);
            for(int k=1;t1[k];k++)
            {
                while(pos>0 && s[pos+1]!=t1[k])
                  pos=nxt[pos];
                if(s[pos+1]==t1[k]) pos++;
                if(pos==len)
                {
                    for(int j=1;t1[j];j++) tmp[j]=t1[j];
                    for(int j=1;j<=len;j++) tmp[k-len+j]=s2[i][j];
                    bool flag=true;
                    for(int j=1;t1[j];j++) flag&=(tmp[j]==t2[j]);
                    ans+=flag;
                }
            }
            memset(s,0,sizeof(s));
        }
        printf("%d\n",ans);
    }
	return 0;
}

