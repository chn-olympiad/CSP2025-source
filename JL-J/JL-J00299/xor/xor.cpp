#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N],sum[N],ans;
bool st[N];
string f(int x)
{
    string s;
    int t=x;
    while (t)
    {
        s+=((t%2)+'0');
        t/=2;
    }
    string anss;
    for (int i=0;i<s.size();i++)
    {
        anss+=s[s.size()-i-1];
    }
    return anss;
}
int v(int x,int y)
{
    string tx=f(x),ty=f(y),xs,ys;
    if (tx.size()<ty.size())
    {
      for (int i=0;i<ty.size()-tx.size();i++) xs+='0';
    }
    else if (ty.size()<tx.size())
    {
      for (int i=0;i<tx.size()-ty.size();i++) ys+='0';
    }
    xs+=tx;
    ys+=ty;
    string res;
    for (int i=0;i<xs.size();i++)
    {
        if (ys[i]=='0') res+=xs[i];
        else if (ys[i]=='1')
        {
            if (xs[i]=='0') res+='1';
            else res+='0';
        }
    }
    int anss=0,tmp=1;
    string an;
    bool flag=0;
    for (int i=0;i<res.size();i++)
    {
        if (res[i]=='1')    flag=1;
        if (flag)   an+=res[i];
    }
    for (int i=an.size()-1;i>=0;i--)
    {
        anss+=(an[i]-'0')*tmp;
        tmp*=2;
    }
    return anss;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)  scanf("%d",&a[i]);
    sum[1]=a[1];
    for (int i=2;i<=n;i++) sum[i]=sum[i-1]^a[i];
    //for (int i=1;i<=n;i++)  cout<<sum[i]<<" ";
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            if (i==j && a[i]==k)
            {

                ans++;
                i++;
                j=i;
                continue;
            }
            if (v(sum[j],sum[i-1])==k)
            {
                i=j+1;
                ans++;
            }
        }
    }
    cout<<ans;
}
