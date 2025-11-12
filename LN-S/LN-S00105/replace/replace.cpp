#include<bits/stdc++.h>
using namespace std;
string s1[1010],s2[1010],t1,t2;
int next1[1010][1010],next2[1010][1010],f1[1010],f2[1010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,ans,l,r;
    bool flag;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        s1[i]=' '+s1[i];
        s2[i]=' '+s2[i];
        for(int j=2,k=0;j<s1[i].length();j++)
        {
            while(k>0&&s1[i][j]!=s1[i][k+1])k=next1[i][k];
            if(s1[i][j]==s1[i][k+1])k++;
            next1[i][j]=k;
        }
        for(int j=2,k=0;j<s2[i].length();j++)
        {
            while(k>0&&s2[i][j]!=s2[i][k+1])k=next2[i][k];
            if(s2[i][j]==s2[i][k+1])k++;
            next2[i][j]=k;
        }
    }
    while(q--)
    {
        cin>>t1>>t2;
        if(t1.length()!=t2.length())
        {
            cout<<0<<endl;
            continue;
        }
        ans=0;
        t1=' '+t1;
        t2=' '+t2;
        for(int i=1;i<t1.length();i++)
        {
            if(t1[i]!=t2[i])
            {
                l=i;
                break;
            }
        }
        for(int i=t1.length()-1;i>=1;i--)
        {
            if(t1[i]!=t2[i])
            {
                r=i;
                break;
            }
        }
        //cout<<l<<" "<<r<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=2,k=0;j<t1.length();j++)
            {
                while(k>0&&t1[j]!=s1[i][k+1])k=next1[i][k];
                if(t1[j]==s1[i][k+1])k++;
                f1[j]=k;
            }
            for(int j=2,k=0;j<t2.length();j++)
            {
                while(k>0&&t2[j]!=s2[i][k+1])k=next2[i][k];
                if(t2[j]==s2[i][k+1])k++;
                f2[j]=k;
            }
            if(s1[i].length()-1>=r)
            {
                //flag=1;
                //for(int j=1;j<s1[i].length();j++)
                //{
                //    if(s1[i][j]!=t1[j])
                //    {
                //        flag=0;
                //        break;
                //    }
                //}
                //if(flag)ans++;
                //cout<<ans<<endl;
                //if(strcmp(s1[i],t1.substr(1,s1[i].length()-1))==0&&strcmp(s2[i],t2.substr(1,s2[i].length()-1)))ans++;
                if(s1[i]==t1.substr(0,s1[i].length())&&s2[i]==t2.substr(0,s2[i].length()))ans++;
                //cout<<i<<" "<<s1[i]<<" "<<t1.substr(1,s1[i].length()-1)<<" "<<s2[i]<<" "<<t2.substr(1,s2[i].length()-1)<<endl;
            }
            for(int j=2;j<t1.length();j++)
            {
                //cout<<i<<" "<<j<<" "<<f1[j]<<" "<<f2[j]<<endl;
                if(j-(s1[i].length()-1)+1>l)break;
                if(j<r)continue;
                if(f1[j]==s1[i].length()-1&&f2[j]==s2[i].length()-1)ans++;
                //cout<<i<<" "<<j<<" "<<f1[j]<<" "<<f2[j]<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
