#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x;
}
bool check(string s,int n)
{
    int cnt=0,i;
    for(i=1;i<=n;i++)
    {
        if(s[i]!='a'&&s[i]!='b')
            return 0;
        if(s[i]=='b')
            cnt++;
    }
    return cnt==1;
}
const int base=29;
const long long mod=1231304233;//My lucky number.
long long gethsh(string s,int l,int r)
{
    int i;
    long long val=0,mul=1;
    for(i=l;i<=r;i++)
    {
        val=(val+(s[i]-'a'+1)*mul%mod)%mod;
        mul=mul*base%mod;
    }
    return val;
}
#define M_P(a,b) make_pair(a,b)
int n,q,lens[210000],lent[2][210000],L[210000],MID[2][210000],R[210000];
char shd[5100000];
string s[2][210000],t[2][210000];
map<pair<int,int>,vector<pair<int,int>>> trn;
map<int,bool> exl,exr;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int l,r,ans,i,j;
    long long mul,val;
    shd[0]='#';
    n=read();
    q=read();
    for(i=1;i<=n;i++)
    {
        scanf("%s",shd+1);
        s[0][i]=shd;
        scanf("%s",shd+1);
        s[1][i]=shd;
        lens[i]=strlen(shd)-1;
    }
    for(i=1;i<=q;i++)
    {
        scanf("%s",shd+1);
        t[0][i]=shd;
        lent[0][i]=strlen(shd)-1;
        scanf("%s",shd+1);
        t[1][i]=shd;
        lent[1][i]=strlen(shd)-1;
    }
    exl[0]=exr[0]=1;
    for(i=1;i<=n;i++)
    {
        l=1;
        r=lens[i];
        while(l<=lens[i]&&s[0][i][l]==s[1][i][l])
            l++;
        while(r&&s[0][i][r]==s[1][i][r])
            r--;
        L[i]=gethsh(s[0][i],1,l-1);
        R[i]=gethsh(s[0][i],r+1,lens[i]);
        MID[0][i]=gethsh(s[0][i],l,r);
        MID[1][i]=gethsh(s[1][i],l,r);
        trn[M_P(MID[0][i],MID[1][i])].push_back(M_P(L[i],R[i]));
    }
    for(i=1;i<=q;i++)
    {
        if(lent[0][i]!=lent[1][i])
        {
            puts("0");
            continue;
        }
        l=1;
        r=lent[0][i];
        while(l<=lent[0][i]&&t[0][i][l]==t[1][i][l])
            l++;
        while(r&&t[0][i][r]==s[1][i][r])
            r--;
        MID[0][i]=gethsh(t[0][i],l,r);
        MID[1][i]=gethsh(t[1][i],l,r);
        val=0;
        for(j=l-1;j>=1;j--)
        {
            val=(val*base%mod+t[0][i][j]-'a'+1)%mod;
            exl[val]=1;
        }
        val=0;
        mul=1;
        for(j=r+1;j<=lent[0][i];j++)
        {
            val=(val+(t[0][i][j]-'a'+1)*mul%mod)%mod;
            exr[val]=1;
            mul=mul*base%mod;
        }
        ans=0;
        for(j=0;j<trn[M_P(MID[0][i],MID[1][i])].size();j++)
        {
            if(exl[trn[M_P(MID[0][i],MID[1][i])][j].first]&&exr[trn[M_P(MID[0][i],MID[1][i])][j].second])
                ans++;
        }
        printf("%d\n",ans);
        val=0;
        for(j=l-1;j>=1;j--)
        {
            val=(val*base%mod+t[0][i][j]-'a'+1)%mod;
            exl[val]=0;
        }
        val=0;
        mul=1;
        for(j=r+1;j<=lent[0][i];j++)
        {
            val=(val+(t[0][i][j]-'a'+1)*mul%mod)%mod;
            exr[val]=0;
            mul=mul*base%mod;
        }
    }
    return 0;
}
