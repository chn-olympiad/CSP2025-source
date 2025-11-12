#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long 
using namespace std;
const int N=2e5+10;
const int M=5e6+10;
const int p=13331;
const int spe=114514;
int n,q,fst[N],lens[N],lent[N],us[N];
string s[N][2],t[N][2];
ull rhas[N][2],pw[M],has1[M],has2[M];
map<ull,vector<int> >mp;
ull get1(int l,int r)
{
    return has1[r]-has1[l-1]*pw[r-l+1];
}
ull get2(int l,int r)
{
    return has2[r]-has2[l-1]*pw[r-l+1];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<=M-5;i++)
    {
        pw[i]=pw[i-1]*p;
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
        lens[i]=s[i][0].size();
        s[i][0]=" "+s[i][0];
        s[i][1]=" "+s[i][1];
        vector<int>vec;
        for(int j=1;j<=lens[i];j++)
        {
            if(s[i][0][j]!=s[i][1][j])
            {
                vec.push_back(j);
            }
        }
        ull has=0;
        if(vec.size()!=0)
        {
            us[i]=vec[0];
            for(int j=1;j<vec.size();j++)
            {
                has*=p;
                has+=vec[j]-vec[j-1];
            }
            has*=p;
            has+=spe;
            for(int j=0;j<vec.size();j++)
            {
                has*=p;
                has+=s[i][0][vec[j]];
                has*=p;
                has+=s[i][1][vec[j]];
            }
        }
        mp[has].push_back(i);
        has=0;
        for(int j=1;j<=lens[i];j++)
        {
            has*=p;
            has+=s[i][0][j];
        }
        rhas[i][0]=has;
        has=0;
        for(int j=1;j<=lens[i];j++)
        {
            has*=p;
            has+=s[i][1][j];
        }
        rhas[i][1]=has;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t[i][0]>>t[i][1];
        if(t[i][0].size()!=t[i][1].size())
        {
            cout<<0<<'\n';
            continue;
        }
        lent[i]=t[i][0].size();
        t[i][0]=" "+t[i][0];
        t[i][1]=" "+t[i][1];
        vector<int>vec;
        for(int j=1;j<=lent[i];j++)
        {
            if(t[i][0][j]!=t[i][1][j])
            {
                vec.push_back(j);
            }
        }
        ull has=0;
        if(vec.size()!=0)
        {
            for(int j=1;j<vec.size();j++)
            {
                has*=p;
                has+=vec[j]-vec[j-1];
            }
            has*=p;
            has+=spe;
            for(int j=0;j<vec.size();j++)
            {
                has*=p;
                has+=t[i][0][vec[j]];
                has*=p;
                has+=t[i][1][vec[j]];
            }
        }
        for(int j=1;j<=lent[i];j++)
        {
            has1[j]=has1[j-1]*p+t[i][0][j];
            has2[j]=has2[j-1]*p+t[i][1][j];
        }
        int ans=0;
        vector<int>uss=mp[has];
        for(int j=0;j<uss.size();j++)
        {
            int x=uss[j];
            if(us[x]>vec[0])
            continue;
            int fr=vec[0]-us[x]+1;
            int ed=fr+lens[x]-1;
            if(ed>lent[i])
            continue;
            if(get1(fr,ed)==rhas[x][0]&&get2(fr,ed)==rhas[x][1])
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}