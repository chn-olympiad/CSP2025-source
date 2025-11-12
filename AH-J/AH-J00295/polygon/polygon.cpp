#include<bits/stdc++.h>
using namespace std;
int a[10000];int n;
vector<int> vec;
bool kloi(vector<int> j)
{
    int tot=0;int maxx;
    for(int i=0;i<j.size();i++)
    {
        tot+=a[j[i]];maxx=max(maxx,a[j[i]]);
    }
    if(tot>maxx*2&&j.size()>=3)return true;
    return false;
}long long sum=0;
void dfs(int id)
{
    if(id==n)
    {
        if(kloi(vec))
        {
            sum++;
            sum%=998244353;
        }
        return;
    }
    dfs(id+1);
    vec.push_back(id+1);
    dfs(id+1);
    vec.pop_back();
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0);
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
