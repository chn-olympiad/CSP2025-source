#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> t[5000005];
int l1[N],l2[N],f1[5000005],f2[5000005];
int flag;
int n,q,lens,lent;
string s1[N],s2[N],t1[N],t2[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        lens+=s1[i].size()+s2[i].size();
        for(int j=0;j<s1[i].size();j++) 
        {
            if(s1[i][j]!='a'&&s1[i][j]!='b'||s2[i][j]!='a'&&s2[i][j]!='b') flag=1;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t1[i]>>t2[i];
        lent+=t1[i].size()+t2[i].size();
        for(int j=0;j<t2[i].size();j++)
        {
            if(t1[i][j]!='a'&&t1[i][j]!='b'||t2[i][j]!='a'&&t2[i][j]!='b') flag=1;
        }
    }
    if(flag)
    {
        for(int i=1;i<=q;i++)
        {
            int ans=0;
            if(t1[i].size()!=t2[i].size()) 
            {
                cout<<0<<endl;
                continue;
            }
            f1[0]=(t1[i][0]==t2[i][0]);f2[t1[i].size()]=1;
            for(int j=1;j<t1[i].size();j++) f1[j]=((t1[i][j]==t2[i][j])&f1[j-1]);
            for(int j=t1[i].size()-1;j>=0;j--) f2[j]=((t1[i][j]==t2[i][j])&f2[j+1]);
            for(int j=0;j<t1[i].size();j++)
            {
                if(j!=0&&!f1[j-1]) break;
                for(int k=t1[i].size()-1;k>=j;k--)
                {
                    if(!f2[k+1]) break;
                    for(int p=1;p<=n;p++)
                    {
                        if(s1[p].size()!=k-j+1) continue;
                        int flag=0;
                        for(int q=0;q<s1[p].size();q++)
                        {
                            char a=s1[p][q];
                            char b=t1[i][j+q];
                            if(a!=b)
                            {
                                flag=1;
                                break;
                            } 
                        } 
                        if(!flag)
                        {
                            int f1=0;
                            for(int q=0;q<s2[p].size();q++)
                            {
                                char a=s2[p][q];
                                char b=t2[i][j+q];
                                if(a!=b)
                                {
                                    f1=1;
                                    break;
                                }
                            }
                            if(!f1) 
                            {
                                ans++;
                            }
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<s1[i].size();j++)
            {
                if(s1[i][j]=='b') 
                {
                    l1[i]=j;
                    break;
                }
            }
            for(int j=0;j<s2[i].size();j++)
            {
                if(s2[i][j]=='b')
                {
                    l2[i]=j;
                    break;
                }
            }
            t[l1[i]-l2[i]+N].push_back(i);
        }
        for(int i=1;i<=q;i++)
        {
            int l=0,r=0;
            for(int j=0;j<t1[i].size();j++)
            {
                if(t1[i][j]=='b') 
                {
                    l=j;
                    break;
                }
            }
            for(int j=0;j<t2[i].size();j++)
            {
                if(t2[i][j]=='b')
                {
                    r=j;
                    break;
                }
            }
            int ans=0;
            for(int j=0;j<t[l-r+N].size();j++)
            {
                int id=t[l-r+N][j];
                if(l1[id]<=l&&s1[id].size()-l1[id]<=t1[i].size()-l) ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}