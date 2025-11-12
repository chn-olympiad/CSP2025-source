#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const int MAXN=500000;
int n,r,cnt,ans;
vector<int> v;
vector<pair<int,int> > p;
int main ()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>r;
    fore(i,0,n)
    {
        int x;
        cin>>x;
        v.pb(x);
    }
    fore(i,0,n)
    {
        cnt=v[i];
        if(cnt==r)
        {
            ans++;
            p.pb(mp(i,i));
            continue;
        }
        fore(j,i+1,n)
        {
            cnt^=v[j];
            if(cnt==r)
            {
                p.pb(mp(i,j));
                ans++;
                break;
            }
        }
    }
    sort(p.begin(),p.end());
    fore(i,0,p.size())
    {
        if(p[i].first==-1)continue;
        fore(j,i+1,p.size())
        {
            
                if(p[i].second>=p[j].first)
                {
                    ans-=2;
                    p[j].first=-1;p[j].second=-1;
                    p[i].first=-1;p[i].second=-1;
                    
                }
            
        }
    }
    cout<<ans;
    return 0;
}
