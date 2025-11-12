#include<bits/stdc++.h>
#define int long long
using namespace std;
unsigned long long rp=-1;
const int mx=500005,mmx=2200005;
int n,k,a[mx],s[mx],to,sz[mmx],p[mx],pz,nr,cnt;
vector<int>t[mmx];
vector<pair<int,int>>ps;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;t[0].push_back(0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        t[s[i]].push_back(i);
    }
    for(int i=0;i<=mmx;i++)sz[i]=t[i].size();
    for(int i=1;i<=n;i++)
    {
        to=s[i]^k;//cout<<to<<'\n';
        if(sz[to]==0||i<=*t[to].begin())continue;
        int l=0,r=sz[to]-1,mid;
        while(l<r)
        {
            mid=(l+r+1)/2;
            if(t[to][mid]>=i)r=mid-1;
            else l=mid;
        }
        p[i]=t[to][l]+1;;
    }
    for(int i=1;i<=n;i++)
        if(p[i])ps.push_back({i,i-p[i]});
    sort(ps.begin(),ps.end());pz=ps.size();
    //cout<<pz<<endl;
    for(int i=0;i<pz;i++)
    {
        int l=ps[i].first,r=ps[i].second;
        if(l-r<=nr)continue;
        //cout<<l<<' '<<r<<'\n';
        nr=l,cnt++;
    }
    cout<<cnt;
    return 0;
}

//mo bai xst dalao!
//mo bai wyx dalao!
//mo bai cyh dalao!
//#Shang4Shan3Ruo6Shui4
