#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
pair<int,int> a[N][3];
int t,n;
bool cmp(pair<int,int> x,pair<int,int> y){return x.second > y.second;}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        int cnt[] = {0,0,0},ans = 0;
        vector<int> b[3];
        for(int i = 1;i <= n;i++){
            a[i][0].first = 0,a[i][1].first = 1,a[i][2].first = 2;
            scanf("%lld%lld%lld",&a[i][0].second,&a[i][1].second,&a[i][2].second);
            sort(a[i],a[i] + 3,cmp);
            ans += a[i][0].second,cnt[a[i][0].first]++;
            b[a[i][0].first].push_back(i);
        }
        int flag = -1;
        if(cnt[0] > n / 2) flag = 0;
        else if(cnt[1] > n / 2) flag = 1;
        else if(cnt[2] > n / 2) flag = 2;
        if(~flag){
            vector<int> v;
            for(auto i : b[flag]) v.push_back( a[i][0].second - a[i][1].second);
            sort(v.begin(),v.end());
            for(int i = 0;i < cnt[flag] - n / 2;i++) ans -= v[i];
        }
        cout << ans << "\n";
    }
    return 0;
}