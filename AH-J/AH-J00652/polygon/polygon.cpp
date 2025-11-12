#include<bits/stdc++.h>
using namespace std;

int n;
int a[21];
long long ans=0;
vector<int>k;
map<vector<int>,bool>f;

void dfs(int sum,int maxn,int r,int ch)
{
  if(sum>maxn*2&&ch>=3&&!f[k]){
    ans++;
    f[k]=1;
  }
  if(r==n+1)
    return;
  dfs(sum,maxn,r+1,ch);
  k.push_back(r);
  dfs(sum+a[r],max(maxn,a[r]),r+1,ch+1);
  k.pop_back();
}

int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  dfs(0,0,1,0);
  cout<<ans%998244353<<endl;
  return 0;
}
