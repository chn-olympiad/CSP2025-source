#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans;
struct node{
    int val,id;
}a[N][4];
vector<int>vec[4];
bool cmp(node x,node y)
{
    return x.val>y.val;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1].val>>a[i][2].val>>a[i][3].val;
            a[i][1].id=1;
            a[i][2].id=2;
            a[i][3].id=3;
            sort(a[i]+1,a[i]+1+3,cmp);
            ans+=a[i][1].val;
            vec[a[i][1].id].push_back(a[i][2].val-a[i][1].val);
        }
        for(int i=1;i<=3;i++)
        {
            sort(vec[i].begin(),vec[i].end());
            for(int j=n/2;j<vec[i].size();j++)
            {
                ans+=vec[i][j];
            }
            vec[i].clear();
        }
        cout<<ans<<'\n';
    }
    return 0;
}