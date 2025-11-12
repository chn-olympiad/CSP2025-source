#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <array>

using namespace std;

#define fori(i,a,b)     for(int i=(a);i<=(b);i++)
#define fori0(i,a,b)    for(int i=(a);i<(b);i++)
#define ford(i,a,b)     for(int i=(a);i>=(b);i--)
#define rgall(a)        (a).begin(),(a).end()
#define rgany(a,l,r)    (a).begin()+(l),(a).begin()+(r)
#define rgn(a,n)        rgany(a,0,n)
#define rgo1(a,n)       rgany(a,1,n+1)

ifstream cin("club.in");
ofstream cout("club.out");

array<array<long long,3>,100001> va;
array<vector<long long>,3> vb;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcnt;
    cin>>testcnt;
    while(testcnt--)
    {
        int n;
        cin>>n;
        long long ans=0;
        fori(i,1,n)
        {
            fori(j,0,2)
                cin>>va[i][j];
            int a=max_element(rgall(va[i]))-va[i].begin();
            long long b=1e18;
            fori(j,0,2)
                if(j!=a)
                    b=min(b,va[i][a]-va[i][j]);
            vb[a].push_back(b),ans+=va[i][a];
        }
        fori(i,0,2)
        {
            if(vb[i].size()<=n/2)
                continue;
            sort(rgall(vb[i]));
            fori0(j,0,vb[i].size()-n/2)
                ans-=vb[i][j];
        }
        cout<<ans<<'\n';
        fori(i,0,2)
            vb[i].clear();
    }
    return 0;
}