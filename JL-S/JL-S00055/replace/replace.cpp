#include<bits/stdc++.h>
#define N 200005
#define M 7000005
using namespace std;
struct node
{
    unsigned long long has1,has2;
    unsigned long long hasl,hasr;
    int lenl,lenr;//len/id
    int op,id;
}G[N<<1],tmp[N];
int n,q,cnt,ls1[N],ls2[N],lt1[N],lt2[N],ans[N];
char S1[M],S2[M],T1[M],T2[M];
char *s1[N],*s2[N],*t1[N],*t2[N];
unsigned long long Has[M],po[M];
unsigned long long *has[N];
unsigned long long H(int i,int l,int r)
{
    return has[i][r]-has[i][l-1]*po[r-l+1];
}
bool cmp(node i,node j)
{
    if(i.has1!=j.has1) return i.has1<j.has1;
    if(i.has2!=j.has2) return i.has2<j.has2;
    return i.op<j.op;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    po[0]=1;
    for(int i=1;i<M;i++)
        po[i]=po[i-1]*19260817;
    scanf("%d%d",&n,&q);
    s1[0]=S1,s2[0]=S2,t1[0]=T1,t2[0]=T2,has[0]=Has;
    for(int i=1;i<=n;i++)
    {
        s1[i]=s1[i-1]+ls1[i-1]+5;
        s2[i]=s2[i-1]+ls2[i-1]+5;
        scanf("%s%s",s1[i]+1,s2[i]+1);
        ls1[i]=strlen(s1[i]+1);
        ls2[i]=strlen(s2[i]+1);
        int len=ls1[i];
        int mi=len,ma=0;
        for(int j=1;j<=len;j++)
            if(s1[i][j]!=s2[i][j])
                mi=min(mi,j),ma=max(ma,j);
        if(mi>ma) continue;
        for(int j=1;j<=len;j++)
            Has[j]=Has[j-1]*19260817+s1[i][j];
        cnt++;
        G[cnt].op=0,G[cnt].id=i;
        G[cnt].lenl=mi-1,G[cnt].lenr=len-ma;
        G[cnt].hasl=H(0,1,mi-1),G[cnt].hasr=H(0,ma+1,len);
        G[cnt].has1=H(0,mi,ma);
        for(int j=1;j<=len;j++)
            Has[j]=Has[j-1]*19260817+s2[i][j];
        G[cnt].has2=H(0,mi,ma);
    }
    for(int i=1;i<=q;i++)
    {
        t1[i]=t1[i-1]+lt1[i-1]+5;
        t2[i]=t2[i-1]+lt2[i-1]+5;
        has[i]=has[i-1]+lt1[i-1]+5;
        scanf("%s%s",t1[i]+1,t2[i]+1);
        lt1[i]=strlen(t1[i]+1);
        lt2[i]=strlen(t2[i]+1);
        if(lt1[i]!=lt2[i]) continue;
        int len=lt1[i];
        int mi=len,ma=0;
        for(int j=1;j<=len;j++)
            if(t1[i][j]!=t2[i][j])
                mi=min(mi,j),ma=max(ma,j);
        for(int j=1;j<=len;j++)
            has[i][j]=has[i][j-1]*19260817+t1[i][j];
        cnt++;
        G[cnt].op=1,G[cnt].id=i;
        G[cnt].lenl=mi,G[cnt].lenr=ma;
        G[cnt].has1=H(i,mi,ma);
        for(int j=1;j<=len;j++)
            has[i][j]=has[i][j-1]*19260817+t2[i][j];
        G[cnt].has2=H(i,mi,ma);
    }
    sort(G+1,G+1+cnt,cmp);
    unsigned long long lst1=-1,lst2=-1;
    int sum=0;
    for(int i=1;i<=cnt;i++)
    {
        if(lst1!=G[i].has1||lst2!=G[i].has2)
        {
            sum=0;
            lst1=G[i].has1;
            lst2=G[i].has2;
        }
        if(!G[i].op)
        {
            tmp[++sum]=G[i];
        }
        else
        {
            for(int j=1;j<=sum;j++)
            {
                int l=G[i].lenl,r=G[i].lenr;
                int lenl=tmp[j].lenl,lenr=tmp[j].lenr;
                if(l<=lenl||lt1[G[i].id]-r<lenr) continue;
                if(H(G[i].id,l-lenl,l-1)==tmp[j].hasl&&
                H(G[i].id,r+1,r+lenr)==tmp[j].hasr)
                    ans[G[i].id]++;
            }
        }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    return 0;
}