#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int n,k;
int arr[5005]={0};
void dfs(int i,int k,int mx,int y)
{
    if(i>n)
    {
        return;
    }
    int j;
    if(arr[i]>mx)
    {
        j=arr[i];
    }
    if(k>(mx*2)&&y>=3)
    {
        cnt++;
    }
    dfs(i+1,k+arr[i],j,y+1);
    dfs(i+1,k,mx,y);
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int j=rand();
    dfs(1,0,0,0);
    cout<<cnt;
    return 0;
}
