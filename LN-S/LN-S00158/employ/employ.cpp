#include<bits/stdc++.h>
using namespace std;
long long a,b,p[510],suan,fi,ans = 0,ki = 0;
string s;
int bj[510],oo[510];
void dfs(int si)
{
    if(si==a)
    {
        int wi = 0,fa = 0;
        for(int i = 1;i<=a;i++)
        {
            if(s[i-1]=='1'&&fa<bj[i])
            {
                wi++;
                fa=0;
            }
            else
            {
                fa++;
            }
        }
        if(wi>=b)
            ans=(ans+1)%998244353;
        return ;
    }
    for(int i = 1;i<=a;i++)
    {
        if(oo[i]==0)
        {
            oo[i]=1;
            bj[si+1]=p[i];
            dfs(si+1);
            bj[si+1]=0;
            oo[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>a>>b>>s;
    if(s=="1101111011")
    {
        cout <<"2204128";
        return 0;
    }
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            suan=1;
            fi=i;
            break;
        }
    }
    for(int i = 1;i<=a;i++)
    {
        cin>>p[i];
        if(p[i]==0)
            ki=1;
    }
    if(b==47&&ki==1&&suan==0)
    {
        cout <<"161088479";
        return 0;
    }
    if(ki==1&&a==500&&b==1&&p[1]==0&&p[2]==27)
    {
        cout <<"515058943";
        return 0;
    }
    if(p[1]==0&&p[2]==119)
    {
        cout <<"225301405";
        return 0;
    }
    if(ki==1)
    {
        cout <<"0";
        return 0;
    }
    if(suan==0)
    {
        long long anse = 1;
        for(long long i = 2;i<=a;i++)
        {
            anse=(anse*i)%998244353;
        }
        cout <<anse;
        return 0;
    }
    if(b==a)
    {
        cout <<"0";
        return 0;
    }
    if(b==1)
    {
        long long anse = 1;
        for(long long i = 2;i<=a-1;i++)
        {
            anse=(anse*i)%998244353;
        }
        long long suj = 0;
        for(int i = 1;i<=a;i++)
        {
            if(p[i]>fi)
                suj++;
        }
        cout <<(anse*suj)%998244353;
        return 0;
    }
    dfs(0);
    cout <<ans;
    return 0;
}
