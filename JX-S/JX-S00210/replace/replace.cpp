#include<bits/stdc++.h>
using namespace std;
int q,n;
string s[20005][2],t[20005][2];
int findf(string a,string b)
{
    int flag=1;
    int i,j;
    for(i=0;i<=a.size()-b.size();i++)
    {
        flag=1;
        for(j=0;j<b.size();j++)
        {
            if(a[i+j]!=b[j])
            {
                flag=-1;
                continue;
            }
        }
        if(flag==1)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin>>n>>q;
    for(int ii=1;ii<=n;ii++)
    {
        cin>>s[ii][1]>>s[ii][2];
    }
    for(int ii=1;ii<=q;ii++)
    {
        cin>>t[ii][1]>>t[ii][2];
        int cnt=0;
        for(int l=1;l<=n;l++)
        {
            if(findf(t[ii][1],s[l][1])!=-1)
            {
                string tt,ss;
                char ch[t[ii][1].size()];
                for(int x=0;x<t[ii][1].size();x++)
                {
                    ch[x]=t[ii][1][x];
                    //cout<<ch[x];
                }
                tt=t[ii][1];
                ss=s[l][2];
                for(int i=findf(t[ii][1],s[l][1]);i<=findf(t[ii][1],s[l][1])+s[l][1].size();i++)
                {
                    char sss=ss[i];
                    ch[i]=sss;
                }
                for(int x=0;x<t[ii][1].size();x++)
                {
                    tt[x]=ch[x];
                }
                cout<<tt<<endl;
                if(tt==t[ii][2])
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;

    }
    return 0;
}
