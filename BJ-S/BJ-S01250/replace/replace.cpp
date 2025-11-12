#include <bits/stdc++.h>
#define PLL pair<LL,LL>
#define LL long long
using namespace std;
const int MAXL=5e6+5,MAXN=2e5+5;
const int BASE=29,MOD=1e9+9;
int N,Q;
int tr[MAXL][26];
vector<int>ed[MAXL];
char s1[MAXL],s2[MAXL],t1[MAXL],t2[MAXL];
int tot=0;
LL has1[MAXN],has2[MAXN];
map<PLL,int>mp;
int vis[MAXN];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&N,&Q);
    for(int ii=1;ii<=N;ii++) 
    {
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        int L=strlen(s1+1);
        //printf("L%d\n",L);
        int l=1,r=L;
        while(s1[l]==s2[l]&&l<L) l++;
        while(s1[r]==s2[r]&&r) r--;
        if(l>r) continue;
        LL H1=0,H2=0;
        for(int i=l;i<=r;i++) H1=(H1*BASE+s1[i]-'a'+1)%MOD,H2=(H2*BASE+s2[i]-'a'+1)%MOD;
        int id;
        if(mp[{H1,H2}]>0) id=mp[{H1,H2}];
        else 
        {
            id=++tot;
            mp[{H1,H2}]=id;
        }
      //  printf("%d %d %d\n",l,r,id);
        ++tot;
        int u=id;
        for(int i=l-1;i;i--)
        {
            int c=s1[i]-'a';
            if(!tr[u][c]) tr[u][c]=++tot;
            u=tr[u][c];
        }
       // printf("ed%d\n",u);
        ed[u].push_back(ii);
        u=id+1;
        for(int i=r;i<=L;i++)
        {
            int c=s1[i]-'a';
            if(!tr[u][c]) tr[u][c]=++tot;
            u=tr[u][c];
        }
       // printf("ed%d\n",u);
        ed[u].push_back(ii);
    }
    while(Q--)
    {
        scanf("%s",t1+1);
        scanf("%s",t2+1);
        int L=strlen(t1+1);
        int l=1,r=L;
        while(t1[l]==t2[l]&&l<L) l++;
        while(t1[r]==t2[r]&&r) r--;
        LL H1=0,H2=0;
        for(int i=l;i<=r;i++) H1=(H1*BASE+t1[i]-'a'+1)%MOD,H2=(H2*BASE+t2[i]-'a'+1)%MOD;
        int id;
        if(mp[{H1,H2}]>0) id=mp[{H1,H2}];
        else 
        {
            puts("0");
            continue;
        }
        int u=id;
        for(int i=l-1;i;i--)
        {
            //printf("ED%d\n",u);
            for(int j:ed[u]) vis[j]=Q;
            int c=t1[i]-'a';
            if(!tr[u][c]) tr[u][c]=++tot;
            u=tr[u][c];
        }
        for(int j:ed[u]) vis[j]=Q;
        u=id+1;
        int ans=0;
        for(int i=r;i<=L;i++)
        {
           // printf("ED%d\n",u);
            for(int j:ed[u]) ans+=(vis[j]==Q);
            int c=t1[i]-'a';
            if(!tr[u][c]) tr[u][c]=++tot;
            u=tr[u][c];
        }
        for(int j:ed[u]) ans+=(vis[j]==Q);
        printf("%d\n",ans);
    }
    return 0;
}