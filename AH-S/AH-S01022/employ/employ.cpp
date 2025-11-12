#include<bits/stdc++.h>
using namespace std;
vector<int> a,b,c;
using ll=long long;
ll md=998244353;
void run()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(auto&i:s)i-='0';
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(auto&i:a)cin>>i;
    for(int i=0;i<n;i++)b[i]=i;
    ll ans=0;
    do
    {
        for(int i=0;i<n;i++) c[i]=a[b[i]];
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(cnt>=c[i]||s[i]==0)
            {
                cnt++;
            }
        }
        if(n-cnt>=m)ans++;
        ans%=md;
    }while(next_permutation(b.begin(),b.end()));
    cout<<ans;
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    run();
    cout<<"\n";

    return 0;
}
/*

*/
