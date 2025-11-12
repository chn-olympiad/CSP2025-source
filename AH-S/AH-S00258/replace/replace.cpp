#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long mod = 998244353;
const long long inf = 1e18;
int n , m;
map<pair<string , string> , vector<int> >a;
string x[200005] , y[200005];
bool check(string s1 , string s2)
{
    int cnt = 0;
    for(int i = 0 ; i < s1.size() ; i++)
    {
        if(s1[i] == s2[cnt])cnt++;
        else cnt = 0;
        if(cnt == s2.size())return 1;
    }
    if(cnt == s2.size())return 1;
//    cout<<s1<<' '<<s2<<' '<<cnt<<endl;
    return 0;
}
signed main()
{
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    cin>>n>>m;
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>x[i]>>y[i];
        int l = 0 , r = x[i].size() - 1;
        for(l = 0 ; l < r ; l++)
        {
            if(x[i][l] != y[i][l])break;
        }
        for(r = x[i].size() - 1 ; r > l ; r--)
        {
            if(x[i][r] != y[i][r])break;
        }
        string xx = "" , yy = "";
        for(int j = l ; j <= r ; j++)
        {
            xx += x[i][j];
            yy += y[i][j];
        }
//        cout<<i<<':'<<xx<<' '<<yy<<endl;
        a[make_pair(xx , yy)].push_back(i);
    }
    string u , v;
    for(int i = 1 ; i <= m ; i++)
    {
        ans = 0;
        cin>>u>>v;
        if(u.size() != v.size())
        {
            cout<<0<<endl;
            continue;
        }
        int l = 0 , r = u.size() - 1;
        for(l = 0 ; l < r ; l++)
        {
            if(u[l] != v[l])break;
        }
        for(r = v.size() - 1 ; r > l ; r--)
        {
            if(u[r] != v[r])break;
        }
        string xx = "" , yy = "";
        for(int j = l ; j <= r ; j++)
        {
            xx += u[j];
            yy += v[j];
        }
//        cout<<i<<':'<<xx<<' '<<yy<<' '<<l<<' '<<r<<endl;
        for(int j : a[make_pair(xx , yy)])
        {
            if(check(u , x[j]))ans++;
//            cout<<i<<':'<<j<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
