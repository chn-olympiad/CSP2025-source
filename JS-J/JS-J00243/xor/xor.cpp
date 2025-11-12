#include<bits/stdc++.h>
using namespace std;
int a[500005]={};
int b[3005][3005]={};
struct node
{
    int l;
    int r;
};
vector<node> ans;
bool cmp(node x,node y)
{
    if(x.r!=y.r)
    {
        return x.r<y.r;
    }
    return x.l>y.l;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(i==j)
            {
                b[i][j]=a[j];
                continue;
            }
            b[i][j]=b[i][j-1]^a[j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(b[i][j]==k)
            {
                ans.push_back({i,j});
            }
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    int last=ans[0].r;
    int cnt=1;
    for(int i=1;i<ans.size();i++)
    {
        if(ans[i].l>last)
        {
            cnt++;
            last=ans[i].r;
        }
    }
    cout<<cnt;
    return 0;
}
