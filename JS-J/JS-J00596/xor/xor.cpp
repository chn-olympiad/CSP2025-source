#include <bits/stdc++.h>
using namespace std;
const int M=5e5+10;
struct Node
{
    int x,y;
    bool operator<(const Node& a) const { return y<a.y; }
};
int n,k;
int a[M];
int ans;
vector<Node> vec;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        int sum=0;
        for(int j=i;j<=n;++j)
        {
            sum^=a[j];
            if(sum==k)
            {
                vec.push_back({i,j+1});
                break;
            }
        }
    }
    sort(vec.begin(),vec.end());
//    for(auto i:vec) cout<<i.x<<' '<<i.y<<endl;
    if(!vec.size())
    {
        cout<<0<<endl;
        return 0;
    }
    int st=1;
    int cnt=0;
    while(st<=n && cnt<vec.size())
    {
        while(st>vec[cnt].x && cnt<vec.size()) cnt++;
        if(st>vec[cnt].x)
        {
            cout<<ans<<endl;
            return 0;
        }
        st=vec[cnt].y;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
