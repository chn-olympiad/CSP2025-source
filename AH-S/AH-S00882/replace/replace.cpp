#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string>mp;
unordered_map<string,int>mp1;
unordered_map<int,string>mp2;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        string s,t;
        cin>>s>>t;
        mp[s]=t;
        mp1[s]=1;
    }
    for(int i=1;i<=q;i++)
    {
        string s,tttt;
        cin>>s>>tttt;
        int len=s.size();
        string pp="";
        int cnt1=1;
        for(int j=len-1;j>=0;j--)
        {
            pp=s[j]+pp;
            mp2[cnt1++]=pp;
            //cout<<"j="<<j<<" pp="<<pp<<endl;
        }
        string ss="";
        int ans=0;
        for(int j=0;j<len;j++)
        {
            string t="";
            for(int k=j;k<len;k++)
            {
                t+=s[k];
                if(mp1[t])
                {
                    string o=mp[t],o2=mp2[len-k-1];
                    string o1=ss+o+o2;
                    if(o1==tttt)
                    {
                        ans++;
                    }
                    //cout<<"k="<<k<<" t="<<t<<" o="<<o<<" o2="<<o2<<" o1="<<o1<<" ans="<<ans<<endl;
                }
            }
            ss+=s[j];
            //cout<<"ss="<<ss<<" j="<<j<<endl;
        }
        printf("%d\n",ans);
    }
}
