#include<bits/stdc++.h>
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=1e5+5;
int id,T,n,a[N][3],c[3],w[N];
LL ans;
int main()
{
    fr(club)
    cin.tie(0)->sync_with_stdio(0);cin>>T;
    while(T--)
    {
        cin>>n;c[0]=c[1]=c[2]=0;ans=0;
        for(int i=1;i<=n;i++) for(int j:{0,1,2}) cin>>a[i][j];
        for(int i=1;i<=n;i++) w[i]=max_element(a[i],a[i]+3)-a[i],c[w[i]]++,ans+=a[i][w[i]];
        int t=-1;
        for(int i:{0,1,2}) if(c[i]>n/2) t=i;
        if(t==-1){cout<<ans<<"\n";continue;}
        vector<int>g;
        for(int i=1;i<=n;i++) if(w[i]==t)
        {
            int mx=0;
            for(int j:{0,1,2}) if(j!=t) mx=max(mx,a[i][j]);
            g.push_back(mx-a[i][t]);
        }
        sort(g.begin(),g.end(),greater<int>());
        for(int i=0;i<c[t]-n/2;i++) ans+=g[i];
        cout<<ans<<"\n";
    }
    return 0;
}