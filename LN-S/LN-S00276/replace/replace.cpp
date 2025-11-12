#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string s,t;
        cin>>s>>t;
        mp[s]=t;
    }
    while(q--)
    {
        map<string,int>vis;
        int ans=0;
        string a,b;
        cin>>a>>b;
        if(a.length()<b.length())for(int i=a.length()+1;i<=b.length();i++)a+=' ';
        if(b.length()<a.length())for(int i=b.length()+1;i<=a.length();i++)b+=' ';
        for(int i=0;i<a.length();i++)
        {
            for(int j=i+1;j<=a.length();j++)
            {
                string ta="",tb="";
                int flag=0;
                for(int k=i;k<=j;k++)ta+=a[k],tb+=b[k];
                for(int k=0;k<i;k++)
                {
                    if(a[k]!=b[k])flag=1;
                }
                for(int k=j+1;k<=a.length();k++)
                {
                    if(a[k]!=b[k])flag=1;
                }
                if(flag==1)continue;
                if(mp[ta]==tb&&vis[ta]!=1){ans++;vis[ta]=1;}
            }
        }
        cout<<ans<<endl;
    }
}
