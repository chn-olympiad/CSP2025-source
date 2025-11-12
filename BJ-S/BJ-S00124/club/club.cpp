#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
pair<int,int> ai[5];
priority_queue<int> s[5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        while (!s[1].empty()) s[1].pop();
        while (!s[2].empty()) s[2].pop();
        while (!s[3].empty()) s[3].pop();
        int n;
        cin>>n;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            ai[1]=make_pair(x,1);
            ai[2]=make_pair(y,2);
            ai[3]=make_pair(z,3);
            sort(ai+1,ai+4);
            s[ai[3].second].push(ai[2].first-ai[3].first);
            ans+=ai[3].first;
        }
        while (s[1].size()>n/2)
        {
            ans+=s[1].top();
            s[1].pop();
        }
        while (s[2].size()>n/2)
        {
            ans+=s[2].top();
            s[2].pop();
        }
        while (s[3].size()>n/2)
        {
            ans+=s[3].top();
            s[3].pop();
        }
        cout<<ans<<'\n';
    }
}
