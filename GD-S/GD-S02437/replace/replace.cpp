#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
long long n,m,i,j,k,q,cs=0;
string s[N][2],t1,t2;
bool tbd(string s)
{
    bool  ans=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='a'&&s[i]!='b') ans=0;
    }
    return ans;
}
long long g(string s1,long long l,string m)
{
    long long i;
    for(i=l;i<l+m.size();i++)
    {
        if(s1[i]!=m[i-l]) return 0;
    }
    return 1;
}
bool f(string s1,string s2,long long l,string m)
{
    int i;
    for(i=l;i<l+m.size();i++)
    {
        s1[i]=m[i];
    }
    return s1==s2;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
        cin>>s[i][0]>>s[i][1];
        if(tbd(s[i][0])==0||tbd(s[i][1])==0) cs=1;
    }
    if(n>200)
    {
        long long p[N][2],p1,p2,ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<s[i][0].size();j++)if(s[i][0][j]=='b') p[i][0]=j;
            for(j=0;j<s[i][1].size();j++)if(s[i][1][j]=='b') p[i][1]=j;
        }
        for(;q>0;q--)
        {
            ans=0;
            cin>>t1>>t2;
            for(j=0;j<t1.size();j++)
            {
                if(t1[j]=='b') p1=j;
            }
            for(j=0;j<t2.size();j++)
            {
                if(t2[j]=='b') p2=j;
            }
            for(i=0;i<n;i++)
            {
                if(p[i][0]-p[i][1]==p1-p2)
                {
                    if(s[i][0].size()>=t1.size())
                    {
                        if(p1>=p[i][0]&&s[i][0].size()-p[i][0]>=t1.size()-p1)
                        {
                            ans++;
                        }
                    }
                }
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    for(;q>0;q--)
    {
        cin>>t1>>t2;
        long long ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=t1.size()-s[i][0].size();j++)
            {
                if(g(t1,j,s[i][0])&&f(t1,t2,j,s[i][1])) ans++;
                if(j>(t1.size())-(s[i][0].size())) break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0; 
}
