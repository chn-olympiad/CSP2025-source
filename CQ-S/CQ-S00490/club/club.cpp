#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=2e5+10;
mt19937 rnd(time(0));
int n;
vector<int>v[3];
void solve()
{
    v[0].clear(),v[1].clear(),v[2].clear();
    cin >> n;
    int ans=0;
    for ( int i = 1 ; i <= n ; i++ )
    {
        int x,y,z;cin >> x >> y >> z;
        ans+=max({x,y,z});
        if(max({x,y,z})==x)v[0].push_back(x-max(y,z));
        else if(max({x,y,z})==y)v[1].push_back(y-max(x,z));
        else v[2].push_back(z-max(x,y));
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    sort(v[2].begin(),v[2].end());
    if(v[0].size()>n/2)
    {
        int w=v[0].size()-n/2;
        for ( int i = 0 ; i < w ; i++ )ans-=v[0][i];
    }
    if(v[1].size()>n/2)
    {
        int w=v[1].size()-n/2;
        for ( int i = 0 ; i < w ; i++ )ans-=v[1][i];
    }
    if(v[2].size()>n/2)
    {
        int w=v[2].size()-n/2;
        for ( int i = 0 ; i < w ; i++ )ans-=v[2][i];
    }
    cout << ans << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;cin >> T;
    while(T--)solve();
	return 0;
 } 
