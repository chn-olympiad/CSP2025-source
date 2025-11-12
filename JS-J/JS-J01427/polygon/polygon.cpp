#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const int MAXN=0;
int n,ans,cnt;
vector<int> v,q;
void dfs(int a,int b,int c)
{
    int now=0;
    fore(i,a,b+1)
    {
        now+=v[i];
    }
    cout<<now;
    if(now<c)
    {
        return;
    }
    else
    {
        cnt++;
        if(b!=n-1)dfs(a,b+1,c);
        if(b!=n-1)dfs(a+1,b+1,c);
        if(a!=0)dfs(a-1,b-1,c);
    }
}
int solve(int a)
{
    cnt=0;
    int fi=-1;
    for(int i=a-1;i>=0;i--)
    {
        if(q[i]>v[a])
        {
            fi=i;
            break;
        }
    }
    if(fi==-1)
    {
        return 0;
    }
    dfs(0,fi,a);
    return cnt;
}
int main ()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    fore(i,0,n)
    {
        int x;
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end());
    fore(i,0,n)
    {
        if(i==0)
        {
            q.pb(v[i]);
            continue;
        }
        q.pb(q[i-1]+v[i]);
        cout<<q[i];
    }
    fore(i,2,n)
    {
        ans+=solve(i);
    }
    cout<<ans;
    return 0;
}
