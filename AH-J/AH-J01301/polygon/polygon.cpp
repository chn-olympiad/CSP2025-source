#include<bits/stdc++.h>
using namespace std;
int arr[5005],cnt;
vector<int>ans;
bool check()
{
    int sum=0,max_v=0;
    for(int i=0;i<ans.size();i++)
    {
        sum+=ans[i];
        max_v=max(max_v,ans[i]);
    }
    return (sum>2*max_v);
}
void dg(int n,int l,int r)
{
    if(n==0)
    {
        if(check())cnt++;
        return;
    }
    for(int i=l;i<=r-n+1;i++)
    {
        ans.push_back(arr[i]);
        dg(n-1,i+1,r);
        ans.pop_back();
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=3;i<=n;i++)
        dg(i,1,n);
    cout<<cnt;
    return 0;
}
