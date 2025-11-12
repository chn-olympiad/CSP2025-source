#include<bits/stdc++.h>
#define mod 998244353
#define INF 1000000000
using namespace std;
const int maxn=2e5+5;
int n,q;
int ans[maxn];
int ss[maxn],tt[maxn];
string s[maxn],t[maxn];
int read()
{
    int u=0,v=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') v=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        u=(u<<3)+(u<<1)+(ch^48);
        ch=getchar();
    }
    return u*v;
}
void print(int x)
{
    if(x<0) x=-x,putchar('-');
    if(x<10) putchar(x+48);
    else print(x/10),putchar(x%10+48);
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int uuu=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>t[i];
        uuu+=s[i].length();
    }
    if(n<=1000 && q<=1000 && uuu<=10000)
    {
        while(q--)
        {
            long long ans=0;
            string u,v;
            cin>>u>>v;
            for(int j=1;j<=n;j++)
            for(int i=0;i<u.size()-s[j].size()+1;i++)
            {
                bool ff=1;
                for(int i1=0;i1<s[j].length() && i+i1<u.length();i1++)
                    if(s[j][i1]!=u[i+i1])
                    {
                        ff=0;
                        break;
                    }
                if(ff)
                {
                    //cout<<q<<" "<<j<<" "<<i<<"\n";
                    string s0="";
                    for(int i1=0;i1<i;i1++)
                        s0+=u[i1];
                    s0+=t[j];
                    for(int i1=i+s[j].length();i1<u.length();i1++)
                        s0+=u[i1];
                    if(s0==v) ans++;
                    //cout<<s0<<" "<<v<<"\n";
                }
            }
            cout<<ans<<"\n";
        }
    }
    else if(q==1 && n<=1000)
    {

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<s[i].length();j++)
            {
                if(s[i][j]=='b') ss[i]=j;
                if(t[i][j]=='b') tt[i]=j;
            }
        }
        string xx,yy;
        int uu=0,vv=0;
        cin>>xx>>yy;
        int ans=0;
        for(int j=0;j<xx.length();j++)
        {
            if(xx[j]=='b') uu=j;
            if(yy[j]=='b') vv=j;
        }
        for(int i=1;i<=n;i++)
        {
            if(ss[i]-tt[i]==uu-vv)
            {
                if(ss[i]<=uu && s[i].length()-tt[i]<=yy.length()-vv) ans++;
            }
        }
        cout<<ans;

    }
    else
    {
        while(q--)
        {
            long long ans=0;
            string u,v;
            cin>>u>>v;
            for(int j=1;j<=n;j++)
            for(int i=0;i<u.size()-s[j].size()+1;i++)
            {
                bool ff=1;
                for(int i1=0;i1<s[j].length() && i+i1<u.length();i1++)
                    if(s[j][i1]!=u[i+i1])
                    {
                        ff=0;
                        break;
                    }
                if(ff)
                {
                    //cout<<q<<" "<<j<<" "<<i<<"\n";
                    string s0="";
                    for(int i1=0;i1<i;i1++)
                        s0+=u[i1];
                    s0+=t[j];
                    for(int i1=i+s[j].length();i1<u.length();i1++)
                        s0+=u[i1];
                    if(s0==v) ans++;
                    //cout<<s0<<" "<<v<<"\n";
                }
            }
            cout<<ans<<"\n";
        }
    }

    return 0;
}
