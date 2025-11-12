#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
vector<int> pre1[200010];
vector<int> pre2[200010];
string s1[200010],s2[200010],t1,t2;
int m1[200010],m2[200010];
void match1(int s,string t)
{
    for(int i=1;i<=t.size()-1;i++)
    {
        int now=m1[i-1];
        while(now>0&&s1[s][now+1]!=t[i]) now=pre1[s][now];
        if(s1[s][now+1]==t[i])
        {
            m1[i]=now+1;
        }
        else
        {
            m1[i]=0;
        }
    }
    return ;
}
void match2(int s,string t)
{
    for(int i=1;i<=t.size()-1;i++)
    {
        int now=m2[i-1];
        while(now>0&&s2[s][now+1]!=t[i]) now=pre2[s][now];
        if(s2[s][now+1]==t[i])
        {
            m2[i]=now+1;
        }
        else
        {
            m2[i]=0;
        }
    }
    return ;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int _=1;_<=n;_++)
    {
        cin>>s1[_]>>s2[_];
        int x=s1[_].size();
        s1[_]='0'+s1[_];
        pre1[_].push_back(0);pre1[_].push_back(0);
        for(int i=2;i<=x;i++)
        {
            int now=pre1[_][i-1];
            while(now>0&&s1[_][now+1]!=s1[_][i]) now=pre1[_][now];
            if(s1[_][now+1]==s1[_][i])
            {
                pre1[_].push_back(now+1);
            }
            else
            {
                pre1[_].push_back(0);
            }
        }

        s2[_]='0'+s2[_];
        pre2[_].push_back(0);pre2[_].push_back(0);
        for(int i=2;i<=x;i++)
        {
            int now=pre2[_][i-1];
            while(now>0&&s2[_][now+1]!=s2[_][i]) now=pre2[_][now];
            if(s2[_][now+1]==s2[_][i])
            {
                pre2[_].push_back(now+1);
            }
            else
            {
                pre2[_].push_back(0);
            }
        }
    }
    while(q--)
    {
        cin>>t1>>t2;
        ans=0;
        if(t1.size()!=t2.size())
        {
            cout<<0<<endl;
            continue;
        }
        int bg=-1,ed=-1,x=t1.size();
        t1='0'+t1;
        t2='0'+t2;
        for(int i=1;i<=x;i++)
        {
            if(t1[i]!=t2[i])
            {
                if(bg==-1) bg=ed=i;
                else ed=i;
            }
        }
        for(int _=1;_<=n;_++)
        {
            int len=s1[_].size()-1;
            match1(_,t1);
            match2(_,t2);
            for(int i=1;i<=x;i++)
            {
                if(m1[i]==m2[i]&&m1[i]==len)
                {
                    int l=i-len+1;
                    if(bg==-1)ans++;
                    else
                    {
                        if(l<=bg&&ed<=i) ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
