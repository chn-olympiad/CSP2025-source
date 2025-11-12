#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
inline int read()
{
    char ch=getchar();
    int w=0,c=1;
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')c=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        w=(w<<1)+(w<<3)+ch-48;
        ch=getchar();
    }
    return w*c;
}
#define maxn 222222
string s[maxn][2];
int n,T;
void solve()
{
    string t1,t2;
    cin>>t1>>t2;
    int l,r;
    for(int i=0;i<t1.size();i++)
        if(t1[i]==t2[i])continue;
        else{l=i;break;}
    for(int i=t1.size()-1;i>=0;i--)
        if(t1[i]==t2[i])continue;
        else{r=i;break;}
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int l0=0,r0=0,l1=0,r1=0;
        for(int j=0;j<s[i][0].size();j++)
            if(s[i][0][j]!=t1[0])continue;
            else{l0=j;break;}
        for(int j=s[i][0].size()-1;j>=0;j--)
            if(s[i][0][j]!=t1[t1.size()-1])continue;
            else{r0=j;break;}
        for(int j=0;j<s[i][1].size();j++)
            if(s[i][1][j]!=t2[0])continue;
            else{l1=j;break;}
        for(int j=s[i][1].size()-1;j>=0;j--)
            if(s[i][1][j]!=t2[t2.size()-1])continue;
            else{r1=j;break;}
        if(s[i][0]==t1)l0=0,r0=s[i][0].size()-1;
        if(s[i][1]==t2)l1=0,r1=s[i][1].size()-1;
        if(l0==l1&&r0==r1&&l0<=l&&r<=r0)cnt++;
    }
    printf("%lld\n",cnt);
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),T=read();
    for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
    while(T--)solve();
    return 0;
}
