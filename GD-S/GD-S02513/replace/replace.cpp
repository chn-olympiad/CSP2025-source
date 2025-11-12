#include <bits/stdc++.h>
using namespace std;
bool AA;
const int N = 5e6 + 5,M = 1e7 + 2300;
int n,m,tot,head,tail,rt[N],son[M][28],fail[M],cnt[M],q[M];
char s1[N],s2[N],t[N << 1];
void insert(int x,int len)
{
    for(int i = 1;i <= len;i++)
    {
        int k = (t[i] == '#' ? 26 : (t[i] == '?' ? 27 : t[i] - 'a'));
        if(!son[x][k]) son[x][k] = ++tot;
        x = son[x][k];
    }
    cnt[x]++;
}
void build(int rt)
{
    head = 1,tail = 0;
    for(int i = 0;i < 28;i++)
        if(son[rt][i]) fail[son[rt][i]] = rt,q[++tail] = son[rt][i];
        else son[rt][i] = rt;
    while(head <= tail)
    {
        int x = q[head++];
        cnt[x] += cnt[fail[x]];
        for(int i = 0;i < 28;i++)
            if(son[x][i]) fail[son[x][i]] = son[fail[x]][i],q[++tail] = son[x][i];
            else son[x][i] = son[fail[x]][i];
    }
}
int query(int x,int len)
{
    int ret = 0;
    for(int i = 1;i <= len;i++)
    {
        int k = (t[i] == '#' ? 26 : (t[i] == '?' ? 27 : t[i] - 'a'));
        x = son[x][k],ret += cnt[x];
    }
    return ret;
}
bool BB;
int main()
{
//	cerr << (&AA - &BB) / 1024 / 1024 << endl; 
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1,len,s,l,r;i <= n;i++)
    {
        scanf("%s%s",s1 + 1,s2 + 1);
        len = strlen(s1 + 1);
        s = l = r = 0;
        for(int i = 1;i <= len;i++)
            if(s1[i] != s2[i])
            {
                l = i;
                break;
            }
        if(!l) continue;
        for(int i = len;i >= 1;i--)
            if(s1[i] != s2[i])
            {
                r = i;
                break;
            }
        for(int i = 1;i <= len;i++) t[++s] = s1[i],t[++s] = '#',t[++s] = s2[i],t[++s] = '?';
        if(!rt[r - l]) rt[r - l] = ++tot;
        insert(rt[r - l],s);
    }
    for(int i = 0;i < N;i++) if(rt[i]) build(rt[i]);
    for(int i = 1,len,s,l,r;i <= m;i++)
    {
        scanf("%s%s",s1 + 1,s2 + 1);
        len = strlen(s1 + 1);
        if(len != (int)strlen(s2 + 1))
        {
            puts("0");
            continue;
        }
        s = l = r = 0;
        for(int i = 1;i <= len;i++)
            if(s1[i] != s2[i])
            {
                l = i;
                break;
            }
        for(int i = len;i >= 1;i--)
            if(s1[i] != s2[i])
            {
                r = i;
                break;
            }
        if(!rt[r - l])
        {
            puts("0");
            continue;
        }
        for(int i = 1;i <= len;i++) t[++s] = s1[i],t[++s] = '#',t[++s] = s2[i],t[++s] = '?';
        printf("%d\n",query(rt[r - l],s));
    }
    return 0;
}
