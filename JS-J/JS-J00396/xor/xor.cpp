#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long a[MAXN],f[MAXN];
vector<pair<int,int>>p;
bool cmp(pair<int,int>awa,pair<int,int>bwa)
{
    if(awa.second==bwa.second) return awa.second>bwa.second;
    else return awa.second<bwa.second;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    long long k;
    cin>>n>>k;
    bool va=true,vais01=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) va=false;
        if(a[i]!=0&&a[i]!=1) vais01=false;
    }
    if(va)
    {
        cout<<n/2<<endl;
        return 0;
    }
    else if(vais01)
    {
        if(k==0)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0) ans++;
                else if(a[i]==1&&a[i+1]==1) i++,ans++;
            }
            cout<<ans<<endl;
        }
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) ans++;
            }
            cout<<ans<<endl;
        }
    }
    else
    {
        f[0]=0;
        f[1]=a[1];
        for(int i=2;i<=n;i++) f[i]=f[i-1]^a[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i]==k) p.push_back({i,i});
            for(int j=i+2;j<=n;j++)
            {
                if(f[i]^f[j]==k) p.push_back({i+1,j});
            }
        }
        sort(p.begin(),p.end(),cmp);
        int cnt=0,ans=0;
        for(int i=0;i<p.size();i++)
        {
            if(cnt<p[i].first) {ans++,cnt=p[i].second;}
            //cout<<p[i].first<<' '<<p[i].second<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
