#include<bits/stdc++.h>
using namespace std;
int s[5002];
int n ,ans;
//int b[5002];
vector<int> v;
void dfs(int num,int sum , int i,int b)
{
    if(num>=3&&sum>2*s[i-1]&&b)
    {
        ans++;
    }
    if(i>n)
    {
        return ;
    }
    //v.push_back(s[i]);
    dfs(num+1,sum+s[i],i+1,1);
//v.pop_back();
    dfs(num,sum,i+1,0);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> s[i];
    }
    sort(s+1,s+1+n);
    dfs(0,0,1,0);

    cout << ans;
    return 0;
}
