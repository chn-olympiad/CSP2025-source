#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+10;
ull Pow[N],base=131;
ull h1[N],h2[N];
int len[N];
ull Hash(string s)
{
    ull ans=0;
    for(int i=0;i<s.size();i++) ans=ans*base+s[i];
    return ans;
}
struct node
{
    vector<ull> h;
    vector<ull> Pow;
    string s;
    void init()
    {
        cin>>s;
        int m=s.size();s=' '+s;
        h.resize(m+1),Pow.resize(m+1);
        Pow[0]=1;
        for(int i=1;i<=m;i++) 
        {
            h[i]=h[i-1]*base+s[i];
            Pow[i]=Pow[i-1]*base;
        }
    }
    ull f(int l,int r){return h[r]-h[l-1]*Pow[r-l+1];}
}t1,t2;
int main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
        string s1,s2;
        cin>>s1>>s2;
        len[i]=s1.size(),h1[i]=Hash(s1),h2[i]=Hash(s2);
    }
    int cnt=0;
    while(q--)
    {
        t1.init(),t2.init();
        if(t1.s.size()!=t2.s.size())
        {
            cout<<"0\n";
            continue;
        }
        int m=t1.s.size()-1;
        int p1=1,p2=m;
        while(t1.s[p1]==t2.s[p1]) p1++;
        while(t1.s[p2]==t2.s[p2]) p2--;
        int ans=0;
        for(int j=p2;j<=m;j++)
            for(int i=1;i<=n;i++)
            {
                if(j-len[i]+1<1||j-len[i]+1>p1) continue;
                if(h1[i]!=t1.f(j-len[i]+1,j)) continue;
                ans+=h2[i]==t2.f(j-len[i]+1,j);
            }
        cout<<ans<<'\n';
        cnt+=(ans>0);
    }
    cerr<<cnt;
    return 0;
}