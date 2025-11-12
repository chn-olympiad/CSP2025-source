#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1145;
int n,q,p=20,ll[N],p2=998244353;
string a[N],b[N];
vector<int>t[N][2];
void _1(string s,int x,int y)
{
    int ans=0;t[x][y].push_back(0);
    for(int i=1;i<s.size();i++)
    {
        t[x][y].push_back(t[x][y][i-1]+(s[i]-'a'+1)*ll[i]%p2);
    }
}
int _2(int x,int y,int z,int u,int v,int l,int r)
{
    int w=(t[x][y][r]-t[x][y][l-1]+p2)%p2;
    int o=t[u][v][r-l+1]*ll[l-1]%p2;
    //int hmx=t[x][y][z]-t[x][y][r]+t[x][y][l-1]+o;
    return (w==o);
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;ll[0]=1;
    for(int i=1;i<=11451;i++)ll[i]=ll[i-1]*p%p2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];a[i]=' '+a[i];b[i]=' '+b[i];
        _1(a[i],i,0);
        _1(b[i],i,1);
    }
    for(int i=1;i<=q;i++)
    {
        string x,y;cin>>x>>y;
        x=' '+x;y=' '+y;
        _1(x,n+i,0);
        _1(y,n+i,1);int cnt=0;
        for(int j=1;j<x.size();j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(j+a[k].size()-1>x.size())continue;
                int g=_2(n+i,0,x.size()-1,k,0,j,j+a[k].size()-2);
                if(!g)continue;
                int ss=t[n+i][0][x.size()-1]-t[n+i][0][j+a[k].size()-2]+t[n+i][0][j-1];
                ss+=t[k][1][a[k].size()-1]*ll[j-1]%p2;ss=(ss+p2)%p2;
                if(ss==t[n+i][1][y.size()-1])cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
