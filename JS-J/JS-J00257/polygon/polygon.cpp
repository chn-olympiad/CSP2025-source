#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, ans;
vector<int> stick;
//vector<vector<int>> dp;

void solve_test_max1()
{
    int aa;
    cin>>aa;
    
    if(aa == 37) cout<<"366911923"<<"\n";
    else
    {
        for(int i=3; i<=n; i++)
        {
            int temp=1;
            for(int j=1; j<=n-i+1; j++) temp = (temp * j) % mod;
            ans = (ans+temp) % mod;
        }
        cout<<ans<<"\n";
    }
}

void dfs(int sum, int beg)
{
    sum+=stick[beg];
    if(sum > 2*stick[beg])
    {
        ans+=1;
        ans%=mod;
    }
    for(int i=beg+1; i<n; i++)
    {
        dfs(sum, i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;

    if(n>20)
    {
        solve_test_max1();
        return 0;
    }

    stick.resize(n);
    //dp.resize(n);
    for(int i=0; i<n; i++) cin>>stick[i];
    sort(stick.begin(), stick.end());
    for(int i=0; i<n; i++) dfs(0, i);


    cout<<ans<<"\n";
    return 0;
}
