#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
const int maxL=5000005;
string s[maxn][3],t[maxn][3];
int ad[maxn][3],n,q,bo[maxL],s1[maxL],s2[maxL],fro,ed;
long long ans;//dp[maxL];
//vector<int> e[maxL];
void KMP(int x,int y)
{
    int len1=s[x][1].length();
    int len2=t[y][1].length();
    for(int i=1;i<=len1;++i)
    {
        s1[i]=(s[x][1][i-1]-'a'+1)*100+(s[x][2][i-1]-'a'+1);
    }
    for(int i=1;i<=len2;++i)
    {
        s2[i]=(t[y][1][i-1]-'a'+1)*100+(t[y][2][i-1]-'a'+1);
    }
    //border
    memset(bo,0,sizeof(bo));
    bo[0]=-1;
    for(int i=2;i<=len1;++i)
    {
        int j=bo[i-1];
        while(s1[j+1]!=s1[i] && j!=-1)
        {
            j=bo[j];
        }
        bo[i]=j+1;
    }
    int j=0;
    for(int i=1;i<=len2;++i)
    {
        while(s1[j+1]!=s2[i] && j!=-1)
        {
            j=bo[j];
        }
        ++j;
        if(j==len1)
        {
            if(i>=ed && i-len1+1<=fro)
                ++ans;
            //e[i-len1].pb(i);
            //printf("%d %d\n",i-len1+1,i);
            j=bo[j];
        }
    }
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    ad[1][1]=1;
    //freopen("replace1.in","r",stdin);
    for(int i=1;i<=n;++i)
    {
        cin>>s[i][1]>>s[i][2];
        //scanf("%s %s",&s[i][1],&s[i][2]);
    }
    //printf("end\n");
    for(int i=1;i<=q;++i)
    {
        ans=0;
        cin>>t[i][1]>>t[i][2];
        int len=t[i][1].length();
        fro=0;ed=len-1;
        while(t[i][1][fro] == t[i][2][fro] && fro<len)
            ++fro;
        while(t[i][1][ed] == t[i][2][ed] && ed>1)
            --ed;
        ++fro;
        ++ed;
        /*
        for(int j=1;j<=t[i][1].length();++j)
            while(!e[i].empty())
                e.pop_back();
        */
        //printf("fro=%d ed=%d\n",fro,ed);
        for(int j=1;j<=n;++j)
        {
            //printf("test i=%d j=%d\n",i,j);
            KMP(j,i);
        }

        printf("%lld\n",ans);
        //memset(dp,0,sizeof(dp));
        //scanf("%s %s",&t[i][1],&t[i][2]);
    }
}
/*
int main()
{
    scanf("%s%s%s%s",s[1][1],s[1][2],t[1][1],t[1][2]);
    //cin>>s[1][1]>>s[1][2]>>t[1][1]>>t[1][2];
    KMP(1,1);
}
*/
