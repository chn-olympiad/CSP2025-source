#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,k,a[N],ans = 0;
int sum[N];
pair<int,int> sumsrt[N];
set<pair<int,int> > areas;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        sum[i] = sum[i - 1] ^ a[i];
        sumsrt[i].first = sumsrt[i - 1].first ^ a[i];
        sumsrt[i].second = i;
    }
    sort(sumsrt + 1,sumsrt + n + 1);
    for(int i = 1;i <= n;i++){
        int tmp = sum[i - 1] ^ k;
        int fd = lower_bound(sumsrt+1,sumsrt+n+1,make_pair(tmp,i)) - sumsrt;
        if(fd != n + 1 && sumsrt[fd].first == tmp)
            areas.insert(make_pair(i,sumsrt[fd].second));
    }
    int mnrt = INT_MIN;
    for(auto i = areas.begin();i != areas.end();i++){
        if(i -> first > mnrt){
            mnrt = i -> second;
            ans++;
        }
        else mnrt = min(mnrt,i -> second);
    }
    cout<<ans;
    return 0;
}
