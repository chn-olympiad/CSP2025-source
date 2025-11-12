#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e6+10;
string a[MAXN];
string b[MAXN];
bool fnd(string x,string y)
{
    int len=x.length();
    for(int i=0;i<len;i++)
    {
        string cmpc;
        for(int j=i;j<len;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cmpc.push_back(x[k]);
            }
            if(cmpc==y)
            {
                return true;
            }
            cmpc="";
        }

    }
    return false;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    /* la=a.length();
    int lb=b.length();
    int cnt=0;
    int lastb=-1;
    for(int i=0;i<la;i++)
    {
        if(a[i]=='b')
        {
            cha2[i].first=cnt;
            if(lastb!=-1)
            {
                cha2[lastb].second=cnt;
            }
            lastb=i;
            cnt=0;
        }
        else
        {
            cnt++;
        }
    }
    cnt=0;
    lastb=-1;
    for(int i=0;i<la;i++)
    {
        if(a[i]=='b')
        {
            cha2[i].first=cnt;
            if(lastb!=-1)
            {
                cha2[lastb].second=cnt;
            }
            lastb=i;
            cnt=0;
        }
        else
        {
            cnt++;
        }
    }*/
    while(q--)
    {
        string s,t;
        cin>>s>>t;
        cout<<ans;
    }
    return 0;
}
