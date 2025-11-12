#include<bits/stdc++.h>
using namespace std;
const int maxl =5000005;
const int maxn = 200005;
int f[maxl][30],d[maxl],fail[maxl];
int mark =1,n,q;
string s,s1,s2;
queue<int> xq;
int x[5];
unordered_map<int,long long> ma;
long long ans=0;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    memset(f,-1,sizeof f);
    for(int i =0;i<26;++i)
        f[0][i]=1;
    for(int i =1;i<=n;++i)
    {

        for(int j=0;j<2;++j)
        {

            cin>>s;
            int u =1;
            for(int h =0;h<s.size();++h)
            {
                if(f[u][s[h]-'a']!=-1)
                    u = f[u][s[h]-'a'];
                else
                {
                    f[u][s[h]-'a'] = ++mark;
                    d[mark] = d[u]+1;
                    u = f[u][s[h]-'a'];
                }
            }
            x[j]=u;
        }
        //cout<<(long long)x[0]<<"****\n";
        ++ma[(long long)x[0]*maxl+x[1]];
        //++ma[x[1]*maxl+x[0]];
    }
    xq.push(1);
    while(!xq.empty())
    {
        int u = xq.front();
        xq.pop();
        for(int i =0;i<26;++i)
        {
            if(f[u][i]==-1)
                f[u][i] =f[fail[u]][i];
            else
            {
                fail[f[u][i]] = f[fail[u]][i];
                xq.push(f[u][i]);
            }

        }
    }
    //for(int i =1;i<=mark;++i)
    //{
    //    cout<<i<<' '<<fail[i]<<'\n';
    //}
    //for(int i =1;i<=n;++i)
    //{
    //   for(int j=0;j<cnt[i].size();++j)
    //        cout<<cnt[i][j]<<' ';
    //    cout<<'\n';
    //}
    for(int i =1;i<=q;++i)
    {
        ans =0;
        cin>>s1>>s2;
        if(s1.size()!=s2.size())
        {
            cout<<"0\n";
            continue;
        }
        int u=1, v=1;
        int l=-1,r;
        for(int j =0;j<s1.size();++j)
        {
            if(s1[j]!=s2[j])
            {
                if(l==-1)
                    l=j;
                r = j;
            }
        }
        //cout<<l<<' '<<r<<'\n';
        for(int j=0;j<s1.size();++j)
        {
            u =f[u][s1[j]-'a'];
            v=f[v][s2[j]-'a'];
            if(j>=r)
            {
                int h1 = u,h2 = v;
                //cout<<h1<<' '<<h2<<'\n';
                while(d[h1]>=j-l+1&&d[h2]>=j-l+1)
                {
                    ans+=ma[(long long)h1*maxl+h2];

                    if(d[h1]>=d[h2])
                        h1=fail[h1];
                    else
                        h2=fail[h2];
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
