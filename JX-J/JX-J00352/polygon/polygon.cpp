#include<bits/stdc++.h>
using namespace std;
int use=0;
int a[5000];
int cnt=0;
int used=0;
int n;
int maxnum;

bool panduan()
{
    if(use<3) return false;
    if(used<=2*maxnum) return false;
    return true;
}

void dfs(int x)
{
    use++;
    used+=a[x];
    maxnum=a[x];
    if(panduan())
    {
        cnt++;
        if(cnt==998244353) cnt=0;
    }
    for(int i=x+1;i<n;i++)
    {
        dfs(i);
    }
    used-=a[x];
    use--;
    return ;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n-2;i++)
    {
        dfs(i);
    }
    cout<<cnt;
    return 0;
}
