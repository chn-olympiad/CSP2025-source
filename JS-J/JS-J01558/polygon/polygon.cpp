#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
int arr[5003];
void dfs(int s,int m,int h,int MAX)
{
    if(m>=3&&h>2*MAX)
    {
        sum++;
    }
    for(s;s<n;s++)
    {
        dfs(s+1,m+1,h+arr[s],max(MAX,arr[s]));
    }
    return ;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    dfs(0,0,0,-1);
    cout<<sum%998244353;
    return 0;
}
