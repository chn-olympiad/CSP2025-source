#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+5,mod=1e9+7,M=2e5+5,K=5e6;
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    return x*f;
} 
void write(int x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int n,m;
string s1[M],s2[M],t1[M],t2[M];
vector<int>g[N];
vector<int>tot;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i];cin>>s2[i];
        int pos1=0,pos2=0;
        for(int j=0;j<s1[i].size();j++){if(s1[i][j]=='b'){pos1=j;break;}}
        for(int j=0;j<s2[i].size();j++){if(s2[i][j]=='b'){pos2=j;break;}}
        g[K+pos2-pos1].push_back(s1[i].size());
        tot.push_back(K+pos2-pos1);
    }
    for(auto v:tot)sort(g[v].begin(),g[v].end());
    for(int i=1;i<=m;i++)
    {
        cin>>t1[i];cin>>t2[i];
        int pos1=0,pos2=0;
        for(int j=0;j<t1[i].size();j++){if(t1[i][j]=='b'){pos1=j;break;}}
        for(int j=0;j<t2[i].size();j++){if(t2[i][j]=='b'){pos2=j;break;}}
        int v=K+pos2-pos1;
        int pos=lower_bound(g[v].begin(),g[v].end(),t1[i].size())-g[v].begin();
        cout<<pos<<"\n";
    }
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    solve();
    return 0;
}