#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node
{
    int d1,d2,d3;
}a[200010];
void solve()
{
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
    int cnt1 = 0,cnt2 = 0,cnt3 = 0;
    int ans = 0;
    for(int i = 1;i <= n;i ++) ans += max(max(a[i].d1,a[i].d2),a[i].d3);
    for(int i = 1;i <= n;i ++) 
    {
        if(a[i].d1 > a[i].d2 && a[i].d1 > a[i].d3) cnt1++;
        if(a[i].d2 > a[i].d1 && a[i].d2 > a[i].d3) cnt2++;
        if(a[i].d3 > a[i].d1 && a[i].d3 > a[i].d2) cnt3++;
    }
    //  cout<<cnt1<<" "<<cnt2<<" " << cnt3<<endl;
    if(cnt1 > n / 2)
    {
        vector<pair<int,int>> vec;
        for(int i = 1;i <= n;i ++)
        {
            if(a[i].d1 > a[i].d2 && a[i].d1 > a[i].d3)
            {
                vec.push_back({a[i].d1,max(a[i].d2,a[i].d3)});
            }
        }
        sort(vec.begin(),vec.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second - a.first > b.second - b.first;
        });
        for(int i = 0;i < cnt1 - n / 2;i ++)
        {
            ans -= vec[i].first - vec[i].second;
        }
    }
    if(cnt2 > n / 2)
    {
        vector<pair<int,int>> vec;
        for(int i = 1;i <= n;i ++)
        {
            if(a[i].d2 > a[i].d1 && a[i].d2 > a[i].d3)
            {
                vec.push_back({a[i].d2,max(a[i].d1,a[i].d3)});
            }
        }
        sort(vec.begin(),vec.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second - a.first > b.second - b.first;
        });
        for(int i = 0;i < cnt2 - n / 2;i ++)
        {
            ans -= vec[i].first - vec[i].second;
        }
    }
    if(cnt3 > n / 2)
    {
        vector<pair<int,int>> vec;
        for(int i = 1;i <= n;i ++)
        {
            if(a[i].d3 > a[i].d2 && a[i].d3 > a[i].d1)
            {
                vec.push_back({a[i].d3,max(a[i].d1,a[i].d2)});
            }
        }
        sort(vec.begin(),vec.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second - a.first > b.second - b.first;
        });
        for(int i = 0;i < cnt3 - n / 2;i ++)
        {
            ans -= vec[i].first - vec[i].second;
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    cin >> _;
    while(_--) solve();
    return 0;
}