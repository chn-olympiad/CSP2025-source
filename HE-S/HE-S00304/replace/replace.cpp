#include<bits/stdc++.h>
#define int long long
const int N=2e5+5;
using namespace std;
int n,q;
struct node 
{
    string s,t;
}st[N];
int sum[N];
string ss,tt;
int maxsiz;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>st[i].s>>st[i].t;
        st[i].s=' '+st[i].s;
        st[i].t=' '+st[i].t;
        maxsiz=max((int)st[i].s.size()-1,maxsiz);
    }
    if(n<=1000&&maxsiz<=2001)
    {
        while(q--)
        {
            int tot=0,ans=0;
            cin>>ss>>tt;
            ss=' '+ss;
            tt=' '+tt;
            int nn=ss.size()-1;
            for(int i=1;i<ss.size();i++)
            sum[i]=sum[i-1]+(ss[i]!=tt[i]);
            for(int i=1;i<=n;i++)
            {
                
                int nnn=st[i].s.size()-1;
                int f=0;
                for(int j=1;j<=nn;j++)
                {
                    string nw=ss;
                    bool ff=1;
                    for(int k=1;k<=nnn;k++)
                    {
                        if(st[i].s[k]!=nw[j+k-1])
                        {
                            ff=0;
                            break;
                        }
                        nw[j+k-1]=st[i].t[k];
                    }
                    if(!ff)
                        continue;
                    f+=(nw==tt);
                }
                ans+=f;
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
    
}