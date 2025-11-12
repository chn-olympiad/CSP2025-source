#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005];
string szp(int n)
{
    string s="";
    while(n>0)
    {
        int g=n%2;
        s=s+char(g+48);
        n/=2;
    }
    return s;
}
int pzs(string s)
{
    int n=0,w=1;
    for(int i=s.size()-1;i>=0;i--)
    {
        n+=int(s[i]-48)*w;
        w*=2;
    }
    return n;
}
string yh(string s1,string s2)
{
    string s="";
    int s1s=s1.size(),s2s=s2.size();
    for(int i=1;i<=min(s1s,s2s);i++)
    {
        int shu1=s1s-i,shu2=s2s-i;
        if(s1[shu1]==s2[shu2])
        {
            s=s+'1';
        }
        else
        {
            s=s+'0';
        }
    }
    return s;
}
int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int f=0,j=i,ans=a[i];
        while(ans!=k&&j<=n)
        {
            j++;
            ans=pzs(yh(szp(a[i]),szp(ans)));
            //cout<<ans<<'\n';
            if(ans==k)
            {
                f=1;
                break;
            }
        }
        if(f==1||ans==k)
        {
            b[i]=j;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=0)
        {
            sum+=1;
            //cout<<i<<' ';
        }
    }
    cout<<sum;
    return 0;
}