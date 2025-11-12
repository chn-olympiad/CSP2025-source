#include <bits/stdc++.h>
using namespace std;
int a[500005],ans,n,k,vis[2000][2000];
int f2tx(string x)
{
    int x10=0;
    int wei=1;
    for(int i=x.size()-1;i>=0;i--)
    {
        x10+=(x[i]-48)*wei;
        wei*=2;
    }
    return x10;
}
string fxt2(int x)
{
    string x2="";
    while(x!=0)
    {
        x2=char(x%2+48)+x2;
        x/=2;
    }
    return x2;
}
string xor2(string x1,string x2)
{
    int mins;
    if(x1.size()>x2.size())
    {
        mins=x2.size();
        for(int i=1;i<=x1.size()-mins;i++)
            x2='0'+x2;
    }
    if(x1.size()<x2.size())
    {
        mins=x1.size();
        for(int i=1;i<=x2.size()-mins;i++)
            x1='0'+x1;
    }
    string ansx="";
    for(int i=0;i<x1.size();i++)
    {
        if(x1[i]==x2[i])
            ansx+='0';
        else
            ansx+='1';
    }
    return ansx;
}
int dfs(int l,int r)
{
    if(vis[l][r]!=0)
    {
        if(vis[l][r]==INT_MAX)
            return 0;
        else
            return vis[l][r];
    }
    if(l==r)
    {
        if(a[l]==k)
            return 1;
        else
            return 0;
    }
    if(r-l==1)
        if(f2tx(xor2(fxt2(a[l]),fxt2(a[r])))==k)
            return 1;
        else
            return 0;
    int maxt=0,maxl,maxr;
    for(int i=l;i<r;i++)
    {
        maxl=0;
        maxr=0;
        maxl=dfs(l,i);
        maxr=dfs(i+1,r);
        if(maxl==0)
        {
            string ls=fxt2(a[l]);
            for(int j=l+1;j<=i;j++) ls=xor2(ls,fxt2(a[j]));
            if(f2tx(ls)==k)
                maxl=1;
        }
        if(maxr==0)
        {
            string rs=fxt2(a[i+1]);
            for(int j=i+2;j<=r;j++) rs=xor2(rs,fxt2(a[j]));
            if(f2tx(rs)==k)
                maxr=1;
        }
        maxt=max(maxt,maxl+maxr);
     }
    if(maxt!=0)
        vis[l][r]=maxt;
    else
        vis[l][r]=INT_MAX;
    return maxt;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<dfs(1,n)<<endl;

    return 0;
}
