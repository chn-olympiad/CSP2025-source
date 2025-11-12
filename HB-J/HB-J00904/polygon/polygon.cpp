#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long n;
long long maxq = -1;
long long ans;
vector <long long> als;

vector <long long> hed;

long long c(long long down_, long long head_)
{
    int ans_=1;
    for(long long i = 0; i < head_; i++)
    {
        ans_ *= down_ - i;
    }
    for(long long i = 0; i < head_; i++)
    {
        ans_ /= i + 1;
    }
    return ans_;
}

int fun1()
{
    ans=1;
    for(int i = 0; i < n; i++)
    {
        ans *= 2;
        ans %= 998244353;
    }
    ans -= c(n, 2);
    ans -= n;
    ans -= 1;
    ans %= 998244353;
    cout << ans;
    return 0;
}

int dfs(int a ,int b,int c,int d)
{
    if(a==n)
    {
        if(c>=3 && b>d*2)
        {
            ans++;

        }
        return 0;
    }
    dfs(a+1,b,c,d);
    dfs(a+1,b+als[a],c+1,als[a]);
    return 0;
}
    

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    
    cin >> n;
    for(long long i = 0; i < n; i++)
    {
        long long in;
        cin >> in;
        als.push_back(in);
        maxq = max(maxq, in);
    }
    sort(als.begin(),als.end());

    if(maxq == 1)
    {
        fun1;
    }
    else
    {
        dfs(0,0,0,0);
        cout << ans;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
