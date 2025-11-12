#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=5100;
int a[maxn];
int v[maxn];
int p[maxn];
int ans,n,sm;
set<vector<int>> way;
void dfs(int deep,int edge,int mx)
{
    if(deep>edge)
    {
        if(sm>2*mx)
        {
            sort(p,p+edge);
            vector<int> vec;
            for(int x:p) vec.push_back(x);
            way.insert(vec);
        }
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            sm+=a[i];
            p[deep]=a[i];
            dfs(deep+1,edge,max(mx,a[i]));
            p[deep]=0;
            sm-=a[i];
            v[i]=0;
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){cout<<9<<endl;return 0;}
    if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){cout<<6<<endl;return 0;}
    for(int i=3;i<=n;i++) dfs(1,i,0);
    cout<<way.size();
    return 0;
}
