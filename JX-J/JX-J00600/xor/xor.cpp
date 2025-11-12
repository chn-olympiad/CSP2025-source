#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200001];
int ans;
bool A=true;
void dfs(int zl,int dq,int h)
{
    if(dq==n) {ans=max(ans,zl);return ;}
    if(h==k) {zl++;}
    dfs(zl,dq+1,h^a[dq]);
    dfs(zl,dq+1,h);
    return;
}
int main()
{
    freopen("xor.in","w",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) A=false;
    }
   for(int i=1;i<=n;i++)
   {
       dfs(1,i,a[i]);
   }
   cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
